#include <bits/stdc++.h>
#define MX 111111
using namespace std;
typedef long long ll;
ll c[MX];
void U(int n)
{
    for (; n < MX; n += (n & -n))
        ++c[n];
}
ll Q(int n)
{
    ll s = 0;
    for (; n > 0; n -= (n & -n))
        s += c[n];
    return s;
}
int main()
{
    int n, p;
    while (scanf("%d", &n) && n)
    {
        memset(c, 0, sizeof(c));
        ll a = 0;
        for (int i = 0; i < n; ++i)
            scanf("%d", &p), a += Q(n + 1) - Q(p), U(p);
        puts(a % 2 ? "Marcelo" : "Carlos");
    }
    return 0;
}