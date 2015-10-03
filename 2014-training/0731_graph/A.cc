#include <cstdio>
#include <algorithm>
#define INF (int)1e7
#define MX 500
using namespace std;
int d[MX][MX], s[MX], v[MX];
int main()
{
    int n, m, a, ans = INF;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            d[i][j] = INF, d[i][i] = 0, s[i] = 0;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &a);
        for (int j = 0; j < a; ++j)
            scanf("%d", &v[j]);
        for (int j = 0; j < a - 1; ++j)
            for (int k = j + 1; k < a; ++k)
                d[v[j]][v[k]] = d[v[k]][v[j]] = 1;
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            s[i] += d[i][j];
    for (int i = 1; i <= n; ++i)
        ans = min(ans, s[i]);
    printf("%d\n", ans * 100 / (n - 1));
    return 0;
}