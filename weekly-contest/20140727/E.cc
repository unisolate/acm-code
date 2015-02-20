#include <bits/stdc++.h>
#define MX 10010
using namespace std;
int n, c[MX * 2], d[MX * 2];
int main()
{
    long long s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &c[i], &d[i]);
        c[i + n] = c[i];
        d[i + n] = d[i];
        s += d[i];
    }
    long long ans = -1;
    for (int i = 0; i < n; ++i)
    {
        long long t = 0, p = 0;
        for (int j = i + 1; j < i + n; ++j)
        {
            p += d[j - 1];
            t += min(p, s - p) * c[j];
        }
        if (ans == -1)
            ans = t;
        else ans = min(ans, t);
    }
    printf("%lld\n", ans);
    return 0;
}