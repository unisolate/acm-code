#include <cstdio>
#include <cmath>
#include <algorithm>
#define MX 111111
#define PI 3.141592654
using namespace std;
struct P
{
    int x, h;
} p[MX];
int cmp(P a, P b)
{
    return a.x < b.x;
}
int main()
{
    int t, n, q, c, cas = 0;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d%d", &p[i].x, &p[i].h);
        sort(p, p + n, cmp);
        scanf("%d", &q);
        printf("Case #%d:\n", ++cas);
        while (q--)
        {
            scanf("%d", &c);
            double kl = -1, kr = -1;
            for (int i = 0; i < n; ++i)
            {
                if (p[i].x < c)
                    kl = max(kl, (double)p[i].h / (c - p[i].x));
                else kr = max(kr, (double)p[i].h / (p[i].x - c));
            }
            double ans = PI - atan(kl) - atan(kr);
            printf("%.9lf\n", ans * 180 / M_PI);
        }
    }
    return 0;
}