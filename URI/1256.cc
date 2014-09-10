#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int h[222][222], q[222];
int main()
{
    int t, m, n, p;
    scanf("%d", &t);
    bool f = false;
    while (t--)
    {
        if (f) putchar(10); else f = true;
        memset(q, 0, sizeof(q));
        scanf("%d%d", &m, &n);
        while (n--)
            scanf("%d", &p), h[p % m][q[p % m]++] = p;
        for (int i = 0; i < m; ++i)
        {
            sort(h[i], h[i] + q[i]);
            printf("%d", i);
            for (int j = 0; j < q[i]; ++j)
                printf(" -> %d", h[i][j]);
            printf(" -> \\\n");
        }
    }
    return 0;
}