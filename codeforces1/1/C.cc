#include <bits/stdc++.h>
#define eps 0.000001
using namespace std;
int main()
{
    double x[3], y[3], d[3], b[3];
    for (int i = 0; i < 3; ++i)
        scanf("%lf%lf", &x[i], &y[i]);
    int k = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = i + 1; j < 3; ++j)
            d[k++] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])), printf("%.8lf\n", d[k - 1]);
    sort(d, d + 3);
    k = 0;
    double a,n;
    for (int i = 0; i < 3; ++i)
        for (int j = i + 1; j < 3; ++j)
        {
            b[k++] = acos((d[i] * d[i] + d[j] * d[j] - d[3 - i - j] * d[3 - i - j]) / (2 * d[i] * d[j]));
            printf("%.8lf %.8lf\n", b[k - 1], 2 * M_PI / (M_PI - b[k - 1]));
            double m = 2 * M_PI / (M_PI - b[k - 1]);
            if (m - (int)m < eps)
                n = m, a = b[k - 1];
        }
    // double a = acos((d[0] * d[0] + d[1] * d[1] - d[2] * d[2]) / (2 * d[0] * d[1]));
    // double n = 2 * M_PI / (M_PI - a);
    printf("%.8lf %.8lf\n", a, n);
    double s = n * d[0] * d[0] * sin(2 * M_PI / n) / (4 * (1 - cos(2 * M_PI / n)));
    printf("%.8lf\n", s);
    return 0;
}