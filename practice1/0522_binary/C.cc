#include <cstdio>
#include <algorithm>
#define MAXN 1111
using namespace std;
int n, k, a[MAXN], b[MAXN];
double y[MAXN];
bool ok(double x)
{
    for (int i = 0; i < n; ++i)
        y[i] = a[i] - b[i] * x;
    sort(y, y + n);
    double sum = 0;
    for (int i = k; i < n; ++i)
        sum += y[i];
    return sum >= 0;
}
int main()
{
    while (scanf("%d%d", &n, &k) && n + k)
    {
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i)
            scanf("%d", &b[i]);
        double l = 0, r = 1, m;
        for (int i = 0; i < 100; ++i)
        {
            m = (l + r) / 2.0;
            ok(m) ? l = m : r = m;
        }
        printf("%d\n", (int)(100 * l + 0.5));
    }
    return 0;
}