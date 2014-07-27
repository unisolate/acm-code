#include <iostream>
#include <cstdio>
using namespace std;
int Max(int x, int y)
{
    return x > y ? x : y;
}
int main()
{
    int n, t, m, s, i;
    int a[100000][2];
    while (~scanf("%d%d", &n, &t) && n + t)
    {
        for (i = 0; i < n; i++)
            scanf("%d%d", &a[i][0], &a[i][1]);
        while (t--)
        {
            scanf("%d", &m);
            s = 0;
            for (i = 0; i < n; i++)
                s = s + Max(a[i][0], a[i][1] - m);
            printf("%d\n", s);
        }
    }
    return 0;
}
