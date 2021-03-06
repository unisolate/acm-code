#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000010
typedef long long ll;
ll f[MAXN], p, c;
void init(ll x)
{
    ll i;
    for (i = 1; i * i < x; ++i)
        if (x % i == 0)
            f[p++] = i, f[p++] = x / i;
    if (i * i == x)
        f[p++] = i;
    sort(f, f + p);
}
void run(ll x, ll k)
{
    if (c > 100000)
        return;
    if (k == 0 || x == 1)
    {
        printf("%I64d ", x);
        ++c;
        return;
    }
    for (int i = 0; i < p && x >= f[i]; ++i)
        if (x % f[i] == 0)
            run(f[i], k - 1);

}
int main()
{
    ll x, k;
    scanf("%I64d%I64d", &x, &k);
    init(x);
    run(x, k);
    return 0;
}