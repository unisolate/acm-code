#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    double x, y, c;
    while (~scanf("%lf%lf%lf", &x, &y, &c))
    {
        double l = 0, r = max(x, y), m;
        for (int i = 0; i < 1000; ++i)
        {
            m = (l + r) / 2.0;
            ((1 / c) > ((1 / sqrt(x * x - m * m)) + (1 / sqrt(y * y - m * m)))) ? l = m : r = m;
        }
        printf("%.3lf\n", l);
    }
    return 0;
}
