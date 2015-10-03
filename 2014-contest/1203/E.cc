#include <cstdio>
#include <cstring>
#include <algorithm>
#define MX 555
using namespace std;
char s[MX];
int n, m, p[MX][MX], v[MX][MX], a[MX][MX], b[MX][MX];
int d(int c[555][555], int x, int y, int t)
{
    if (x == n - 1 && y == m - 1)
        return t;
    return min(d(c, x + 1, y, t), min(d(c, x, y + 1, t), min(d(c, x - 1, y, t), d(c, x, y - 1, t))));
}
int dfs(int c[555][555])
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            v[i][j] = 0;
    int x = 0, y = 0;
    v[0][0] = 1;
    while (!(x == n - 1 && y == m - 1))
    {
        if (x + 1 < n && v[x + 1][y] == 0 && c[x + 1][y] == 0)
            ++x, v[x][y] = 1;
        else if (y + 1 < m && v[x][y + 1] == 0 && c[x][y + 1] == 0)
            ++y, v[x][y] = 1;
        else if (x - 1 >= 0 && v[x - 1][y] == 0 && c[x - 1][y] == 0)
            --x, v[x][y] = 1;
        else if (y - 1 >= 0 && v[x][y - 1] == 0 && c[x][y - 1] == 0)
            --y, v[x][y] = 1;
        else break;
    }
    int l = -1;
    if (x == n - 1 && y == m - 1)
    {
        l = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                l += v[i][j];
    }
    return l;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", s);
        for (int j = 0; j < m; ++j)
            if (s[j] == '#')
                p[i][j] = 1, a[i][j] = 1;
    }
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", s);
        for (int j = 0; j < m; ++j)
            if (s[j] == '#')
                p[i][j] = 1, b[i][j] = 1;
    }
    int l = dfs(p);
    if (l != -1 && l == dfs(a) && l == dfs(b))
        puts("YES");
    else puts("NO");
    return 0;
}