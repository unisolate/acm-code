#include <cstdio>
#include <algorithm>
using namespace std;
struct T
{
    int a, b, c, d;
} t[111];
int n;
int cmp(T p, T q)
{
    if (p.b == q.b)
    {
        double x, y;
        if (p.d)
            x = (double)p.c / p.d;
        else x = (double)p.c / (n - 1);
        if (q.d)
            y = (double)q.c / q.d;
        else y = (double)q.c / (n - 1);
        if (x == y)
        {
            if (p.c == q.c)
            {
                return p.a < q.a;
            }
            else return p.c > q.c;
        }
        else return x > y;
    }
    else return p.b > q.b;
}
int main()
{
    int cas = 0, x, y, z, w;
    while (scanf("%d", &n) && n)
    {
        if (cas) putchar(10);
        for (int i = 1; i <= n; ++i)
            t[i].a = i, t[i].b = 0, t[i].c = 0, t[i].d = 0;
        for (int i = 0; i < n * (n - 1) / 2; ++i)
        {
            scanf("%d%d%d%d", &x, &y, &z, &w);
            if (y > w) t[x].b += 2, t[z].b += 1;
            else t[x].b += 1, t[z].b += 2;
            t[x].c += y, t[x].d += w;
            t[z].c += w, t[z].d += y;
        }
        sort(t + 1, t + n + 1, cmp);
        printf("Instancia %d\n", ++cas);
        printf("%d", t[1].a);
        for (int i = 2; i <= n; ++i)
            printf(" %d", t[i].a);
        putchar(10);
    }
    return 0;
}