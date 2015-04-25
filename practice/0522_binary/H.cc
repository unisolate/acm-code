#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAXN 222
#define eps 0.00001
using namespace std;
int n, R;
double ans, xi, yi, xj, yj, xk, yk, x[MAXN], y[MAXN];
double calc(double t)
{
    xk = R * cos(t);
    yk = R * sin(t);
    double a = sqrt((xi - xk) * (xi - xk) + (yi - yk) * (yi - yk)),
           b = sqrt((xj - xk) * (xj - xk) + (yj - yk) * (yj - yk)),
           c = sqrt((xi - xj) * (xi - xj) + (yi - yj) * (yi - yj));
    return acos((a * a + b * b - c * c) / (2 * a * b));
}
double solve(int i, int j)
{
    double l, r, m1, m2, tmp, d, dx, dy, u, v, w, t1, t2, xl, yl, xr, yr;
    xi = x[i]; yi = y[i]; xj = x[j]; yj = y[j];
    dx = xi - xj; dy = yi - yj;
    u = dx * dx + dy * dy;
    v = 2 * xj * dx + 2 * yj * dy;
    w = xj * xj + yj * yj - R * R;
    d = sqrt(v * v - 4 * u * w);
    t1 = (-v - d) / 2 / u;
    t2 = (-v + d) / 2 / u;
    xl = xj + dx * t1;
    yl = yj + dy * t1;
    xr = xj + dx * t2;
    yr = yj + dy * t2;
    l = asin(yl / R);
    r = asin(yr / R);
    if (xl < 0)
        l = M_PI - l;
    if (xr < 0)
        r = M_PI - r;
    if (l > r)
        swap(l, r);
    if (r - l > M_PI)
        l += 2 * M_PI, swap(l, r);
    while (l + eps < r)
    {
        tmp = (r - l) / 3.0;
        m1 = l + tmp;
        m2 = r - tmp;
        calc(m1) < calc(m2) ? l = m1 : r = m2;
    }
    return calc(l);
}
int main()
{
    while (~scanf("%d%d", &n, &R))
    {
        ans = 0;
        for (int i = 0; i < n; ++i)
            scanf("%lf%lf", &x[i], &y[i]);
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                ans = max(ans, solve(i, j));
        printf("%.10lf\n", ans);
    }
    return 0;
}