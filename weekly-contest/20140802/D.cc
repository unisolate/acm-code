#include <bits/stdc++.h>
#define MX 2222
#define MOD ((int)1e9+7)
using namespace std;
int dp[MX][MX];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        dp[1][i] = 1;
    for (int p = 1; p < k; ++p)
        for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; j += i)
                dp[p + 1][j] = (dp[p + 1][j] + dp[p][i]) % MOD;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = (ans + dp[k][i]) % MOD;
    printf("%d\n", ans);
    return 0;
}