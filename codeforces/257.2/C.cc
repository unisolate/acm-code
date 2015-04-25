#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, m, k;
    scanf("%I64d%I64d%I64d", &n, &m, &k);
    if (n + m - 2 < k)
    {
        puts("-1");
        return 0;
    }
    long long x = n * k / (m + n), y = m * k / (m + n);
    long long l = min(x, y) - 10000, r = max(x, y) + 10000;
    if (l <= 1)
        l = 1;
    if (r >= k + 1)
        r = k + 1;
    long long s = 0;
    for (x = l; x <= r; ++x)
    {
        y = k + 2 - x;
        s = max(s, min(n / x, n - (x - 1) * (n / x)) * min(m / y, m - (y - 1) * (m / y)));
    }
    printf("%I64d\n", s);
    return 0;
}