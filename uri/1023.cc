#include <bits/stdc++.h>
using namespace std;
int p[222];
int main()
{
    int cas = 0, n;
    while (scanf("%d", &n) && n)
    {
        if (cas) putchar(10);
        memset(p, 0, sizeof(p));
        int a, b;
        double x = 0, y = 0;
        for (int i = 0; i < n; ++i)
            scanf("%d%d", &a, &b), x += a, y += b, p[b / a] += a;
        printf("Cidade# %d:\n", ++cas);
        bool f = false;
        for (int i = 0; i <= 200; ++i)
            if (p[i])
            {
                if (f) putchar(' '); else f = true;
                printf("%d-%d", p[i], i);
            }
        printf("\nConsumo medio: %.2lf m3.\n", floor((y / x) * 100) / 100);
    }
    return 0;
}