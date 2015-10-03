#include <cstdio>
#include <algorithm>
using namespace std;
int p[1000];
int main()
{
    int m, n, v, cas = 1;
    while (~scanf("%d%d", &m, &n) && m + n)
    {
        for (int i = 0; i < m * n; ++i)
            scanf("%d", &p[i]), p[i] *= 100;
        scanf("%d", &v);
        sort(p, p + m * n);
        int i, s = 0;
        for (i = 1; i < m * n; ++i)
            if (s + (p[i] - p[i - 1])*i > v)
                break;
            else s += (p[i] - p[i - 1]) * i;
        printf("Region %d\n", cas++);
        printf("Water level is %.2lf meters.\n", (p[i - 1] + (double)(v - s) / i) / 100);
        printf("%.2lf percent of the region is under water.\n", (double)100 * i / (m * n));
        putchar(10);
    }
    return 0;
}