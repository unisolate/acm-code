#include <bits/stdc++.h>
using namespace std;
long long n, m, k, s, f;
void ok(long long c)
{
    s = 0, f = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i > c)
            break;
        s += min(c / i, (long long)m);
        if (m * i >= c && c % i == 0)
        {
            --s;
            ++f;
        }
    }
}
int main()
{
    scanf("%I64d%I64d%I64d", &n, &m, &k);
    long long l = 1, r = m * n, mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        ok(mid);
        // printf("%I64d %I64d %I64d %I64d %I64d\n", l, r, mid, s, f);
        if ((s < k) && (s + f >= k) && f)
        {
            printf("%I64d\n", mid);
            break;
        }
        if (s >= k)
            r = mid - 1;
        else l = mid + 1;
    }
    return 0;
}