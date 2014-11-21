#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
double x[4], y[4], s, v;
double ab(double x)
{
    if (x < 0) return -x;
    return x;
}
int main()
{
    int t, cas = 0;
    scanf("%d", &t);
    while (t--)
    {
        for (int i = 0; i < 4; ++i)
            scanf("%lf%lf", &x[i], &y[i]);
        scanf("%lf", &s);
        if (x[2] != x[0])
        {
            double k = (y[0] - y[2]) / (x[0] - x[2]);
            double b = y[0] - k * x[0];
            double z = sqrt(k * k + 1);
            double e = sqrt((x[0] - x[2]) * (x[0] - x[2]) + (y[0] - y[2]) * (y[0] - y[2]));
            double d1 = ((k * x[1] - y[1] + b) / z);
            double d2 = ((k * x[3] - y[3] + b) / z);
            if ((d1 < 0 && d2 < 0) || (d1 > 0 && d2 > 0))
            {
                d1 = ab(d1); d2 = ab(d2);
                v = 0.5 * e * ab(d1 - d2);
            }
            else
            {
                d1 = ab(d1); d2 = ab(d2);
                v = 0.5 * e * ab(d1 + d2);
            }
        }
        else
        {
            double e = ab(y[2] - y[0]);
            double d1 = ab(x[1] - x[0]);
            double d2 = ab(x[3] - x[0]);
            if ((x[1] < x[0] && x[3] < x[0]) || (x[1] > x[0] && x[3] > x[0]))
                v = 0.5 * e * ab(d1 - d2);
            else v = 0.5 * e * (d1 + d2);
        }
        printf("Case #%d: %.2lf\n", ++cas, round(100.0 * s / v) / 100.0);
    }
    return 0;
}