#include <cstdio>
#include <algorithm>
#define MX 10000
using namespace std;
int w[MX], p[MX], r[MX], u[MX], v[MX];
int cmp(int i, int j)
{
    return w[i] < w[j];
}
int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}
void kruskal(int n, int m)
{
    int ans = 0;
    for (int i = 0; i <= n; ++i)
        p[i] = i;
    for (int i = 0; i <= m; ++i)
        r[i] = i;
    sort(r, r + m, cmp);
    for (int i = 0; i < m; ++i)
    {
        int e = r[i], x = find(u[e]), y = find(v[e]);
        if (x != y)
            ans += w[e], p[x] = y;
    }
    printf("%d\n", ans);
}
int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        int m = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                scanf("%d", &w[m]);
                if (i == j)continue;
                u[m] = i;
                v[m] = j;
                ++m;
            }
        kruskal(n, m);
    }
    return 0;
}