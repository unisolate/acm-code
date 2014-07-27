#include <bits/stdc++.h>
#define MX 505
using namespace std;
double r[MX], s[MX], p[MX];
int k, n;
double solve(int d)
{
    if (s[d] >= 0)
        return s[d];
    double res = r[d];
    for (int i = 1; i <= k && d + i <= n; ++i)
        res += p[i] * solve(d + i);
    return s[d] = res;
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas)
    {
        int q[505];
        double x, c;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= k; ++i)
            scanf("%lf", &p[i]);
        for (int i = 1; i <= n; ++i)
        {
            s[i] = -1;
            scanf("%d", &q[i]);
            r[i] = 0;
            for (int j = 0; j < q[i]; ++j)
                scanf("%lf%lf", &c, &x), r[i] += c * x;
        }
        printf("Case #%d: %.6lf\n", cas, solve(1));
    }
    return 0;
}