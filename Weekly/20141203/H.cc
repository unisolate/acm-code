#include <cstdio>
#include <cmath>
#include <algorithm>
#define EPS 0.00001
using namespace std;
int main()
{
    double x[6], y[6], a[3], b[3], k[3];
    for (int i = 0; i < 6; ++i)
        scanf("%lf%lf", &x[i], &y[i]);
    a[0] = sqrt((x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]));
    a[1] = sqrt((x[0] - x[2]) * (x[0] - x[2]) + (y[0] - y[2]) * (y[0] - y[2]));
    a[2] = sqrt((x[1] - x[2]) * (x[1] - x[2]) + (y[1] - y[2]) * (y[1] - y[2]));
    b[0] = sqrt((x[3] - x[4]) * (x[3] - x[4]) + (y[3] - y[4]) * (y[3] - y[4]));
    b[1] = sqrt((x[3] - x[5]) * (x[3] - x[5]) + (y[3] - y[5]) * (y[3] - y[5]));
    b[2] = sqrt((x[4] - x[5]) * (x[4] - x[5]) + (y[4] - y[5]) * (y[4] - y[5]));
    sort(a, a + 3);
    sort(b, b + 3);
    for (int i = 0; i < 3; ++i)
        k[i] = a[i] / b[i];
    if ((k[0] - k[1]) < EPS && (k[1] - k[2]) < EPS)
        puts("YES");
    else puts("NO");
    return 0;
}