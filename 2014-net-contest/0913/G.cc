#include <cstdio>
#include <algorithm>
using namespace std;
int p[1111];
int cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &p[i]);
        sort(p, p + n, cmp);
        double ans = 0;
        for (int i = 0; i < n; ++i)
        {
            double f = 1;
            for (int j = 0; j < i; ++j)
                f *= 0.95;
            ans += f * p[i];
        }
        printf("%lf\n", ans);
    }
    return 0;
}