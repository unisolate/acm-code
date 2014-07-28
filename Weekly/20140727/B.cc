#include <bits/stdc++.h>
using namespace std;
int p[1111][1111];
int main()
{
    int n, m, x, y;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
        scanf("%d%d", &x, &y), p[x][y] = 1, p[y][x] = 1;
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            int t = p[i][j];
            for (int k = j + 1; k <= n; ++k)
            {
                if (p[j][k] == t)
                {
                    if (p[k][i] == t)
                    {
                        ans++;
                    }
                }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}