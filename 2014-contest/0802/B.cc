#include <bits/stdc++.h>
#define MX 1111
#define MOD ((int)1e9+7)
using namespace std;
int dp[MX];
int main()
{
    int n, p, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &p);
        dp[i] = 2;
        for (int j = p; j < i; ++j)
            dp[i] = (dp[j] + dp[i]) % MOD;
        ans = (ans + dp[i]) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}