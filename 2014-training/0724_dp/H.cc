#include <cstdio>
#include <cstring>
#define MX 500
using namespace std;
int dp[MX][MX];
int main()
{
    int t;
    char x[MX], y[MX], z[MX];
    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas)
    {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        scanf("%s%s%s", x, y, z);
        int lx = strlen(x), ly = strlen(y);
        for (int i = 0; i <= lx; ++i)
            for (int j = 0; j <= ly; ++j)
                if ((j && y[j - 1] == z[i + j - 1] && dp[i][j - 1]) ||
                        (i && x[i - 1] == z[i + j - 1] && dp[i - 1][j]))
                    dp[i][j] = 1;
        printf("Data set %d: ", cas);
        if (dp[lx][ly])
            printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
