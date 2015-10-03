#include <cstdio>
#include <algorithm>
#define MX 1000
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
    while (~scanf("%d", &n) && n)
    {
        int m = 0, z;
        char a[10], b[10];
        for (int i = 1; i < n; ++i)
        {
            scanf("%s%d", a, &z);
            for (int j = 0; j < z; ++j)
            {
                scanf("%s%d", b, &w[m]);
                u[m] = a[0] - 'A';
                v[m] = b[0] - 'A';
                ++m;
            }
        }
        kruskal(n, m);
    }
    return 0;
}