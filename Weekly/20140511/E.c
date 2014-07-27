#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 111111
using namespace std;
const long long MOD = 100000007;
int c[MAXN];
void update(int n, int v)
{
    for (; n <= MAXN; n += (n & -n))
        c[n] += v;
}
int read(int n)
{
    int sum = 0;
    for (; n > 0; n -= (n & -n))
        sum += c[n];
    return sum;
}
int main()
{
    int t, n, p, s;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas)
    {
        long long ans = 0, k;
        memset(c, 0, sizeof(c));
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &p);
            s = read(p);
            k = (n - p - i + s);
            ans += (k - 1) * k / 2;
            ans -= k * s;
            update(p, 1);
        }
        printf("Case #%d: %I64d\n", cas, ans % MOD);
    }
    return 0;
}