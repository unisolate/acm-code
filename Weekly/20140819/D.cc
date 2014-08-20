#include <bits/stdc++.h>
#define MX 10000010
using namespace std;
typedef long long ll;
bool prime[MX];
int n, x[MX];
ll c[MX];
void update(int n, int v)
{
    for (; n <= MX; n += (n & -n))
        c[n] += v;
}
ll query(int n)
{
    ll sum = 0;
    for (; n > 0; n -= (n & -n))
        sum += c[n];
    return sum;
}
void findprime(int t)
{
    prime[0] = prime[1] = true;
    for (int i = 2; i <= t; ++i)
        if (!prime[i])
            for (int j = 2 * i; j <= t; j += i)
                prime[j] = true;
    for (int i = 2; i <= t; ++i)
        if (!prime[i])
        {
            int u = 0;
            for (int j = 1; j <= n; ++j)
                if (x[j] % i == 0)
                    ++u;
            update(i, u);
        }
}
int main()
{
    int m, l, r, t = -1;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x[i]), t = max(t, x[i]);
    findprime(t);
    scanf("%d", &m);
    while (m--)
    {
        scanf("%d%d", &l, &r);
        ll ans;
        if (l > MX - 10) ans = 0;
        else if (r > MX - 10) ans = query(MX - 10) - query(l - 1);
        else ans = query(r) - query(l - 1);
        printf("%I64d\n", ans);
    }
    return 0;
}