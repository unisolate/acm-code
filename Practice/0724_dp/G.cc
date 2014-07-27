#include <cstdio>
#include <cstring>
#define MX 1000
using namespace std;
char a[MX], b[MX];
int dp[MX][MX];
int lcs(char x[], char y[])
{
    int la = strlen(x + 1), lb = strlen(y + 1);
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= la; ++i)
        for (int j = 1; j <= lb; ++j)
        {
            if (x[i] == y[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else if (dp[i - 1][j] >= dp[i][j - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i][j - 1];
        }
    return dp[la][lb];
}
int main()
{
    while (~scanf("%s%s", a + 1, b + 1))
        printf("%d\n", lcs(a, b));
    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
#define MX 1001
using namespace std;
char x[MX], y[MX];
int r[MX][MX];
int lcs(int m, int n)
{
    if (m < 0 || n < 0)
        return 0;
    if (r[m][n] != -1)
        return r[m][n];
    if (x[m] == y[n])
        r[m][n] = lcs(m - 1, n - 1) + 1;
    else r[m][n] = max(lcs(m, n - 1), lcs(m - 1, n));
    return r[m][n];
}
int main()
{
    while (~scanf("%s %s", x, y))
    {
        memset(r, -1, sizeof(r));
        printf("%d\n", lcs(strlen(x) - 1, strlen(y) - 1));
    }
    return 0;
}