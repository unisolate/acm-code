#include <cstdio>
using namespace std;
int a[111], x[1111], y[1111];
int main()
{
    int n, k, s, m;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (m = 0; m < k; ++m)
    {
        int mi = 0, ma = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] < a[mi])
            {
                mi = i;
            }
            if (a[i] > a[ma])
            {
                ma = i;
            }
        }
        s = a[ma] - a[mi];
        if (s <= 1)
            break;
        else
        {
            x[m] = ma;
            y[m] = mi;
            --a[ma];
            ++a[mi];
        }
    }
    int mi = 0, ma = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] < a[mi])
        {
            mi = i;
        }
        if (a[i] > a[ma])
        {
            ma = i;
        }
    }
    s = a[ma] - a[mi];
    printf("%d %d\n", s, m);
    for (int i = 0; i < m; ++i)
        printf("%d %d\n", x[i] + 1, y[i] + 1);
    return 0;
}