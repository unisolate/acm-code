#include <cstdio>
#include <cstring>
#define MX 2333
using namespace std;
int p[MX], q[MX], r[MX], dp[MX][MX];
int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m) && n + m)
    {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i)
            scanf("%d", &p[i]);
        for (int i = 0; i < m; ++i)
            scanf("%d", &q[i]);
        for (int i = 0; i < n + m; ++i)
            scanf("%d", &r[i]);
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= m; ++j)
                if ((j && q[j - 1] == r[i + j - 1] && dp[i][j - 1]) ||
                        (i && p[i - 1] == r[i + j - 1] && dp[i - 1][j]))
                    dp[i][j] = 1;
        if (dp[n][m])
            puts("possible");
        else puts("not possible");
    }
    return 0;
}