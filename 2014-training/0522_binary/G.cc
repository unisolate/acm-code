#include <cstdio>
#include <algorithm>
#include <cmath>
#define eps 0.00001 // 容忍的最低精度
#define MAXN 333
#define INF 0x3f3f3f3f
using namespace std;
int n;
double x[MAXN], y[MAXN], vx[MAXN], vy[MAXN], a[MAXN], b[MAXN];
double calc(double t)
{
    for (int i = 0; i < n; ++i)
    {
        a[i] = x[i] + t * vx[i];
        b[i] = y[i] + t * vy[i];
    }
    double dis = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            dis = max(dis, sqrt((a[i] - a[j]) * (a[i] - a[j]) + (b[i] - b[j]) * (b[i] - b[j])));
    return dis;
}
int main()
{
    int t, cas = 1;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%lf%lf%lf%lf", &x[i], &y[i], &vx[i], &vy[i]);
        double l = 0, r = INF, tmp, m1, m2;
        while (l + eps < r)
        {
            tmp = (r - l) / 3.0;
            m1 = l + tmp;
            m2 = r - tmp;
            calc(m1) > calc(m2) + eps ? l = m1 : r = m2;
        }
        printf("Case #%d: %.2lf %.2lf\n", cas++, l, calc(l));
    }
    return 0;
}