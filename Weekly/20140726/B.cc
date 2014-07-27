#include <bits/stdc++.h>
#define MX 501
#define INF 300001
using namespace std;
int n, p[MX], dp[INF][MX];
int f(int a, int i)
{
    if (dp[a][i] != -1)
        return dp[a][i];
    if (i == n - 1)
        return dp[a][i] = ((a - p[i]) >= 0 ? (a - p[i]) : a);
    dp[a][i] = INF;
    if (a - p[i] >= 0)
        dp[a][i] = min(dp[a][i], f(a - p[i], i + 1));
    return dp[a][i] = min(dp[a][i], f(a, i + 1));
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        int s = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &p[i]), s += p[i];
        sort(p, p + n);
        int ans = 2 * f(s / 2, 0);
        if (s % 2)
            ++ans;
        printf("%d\n", ans);
    }
    return 0;
}