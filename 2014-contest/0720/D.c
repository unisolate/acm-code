#include <stdio.h>
#define MOD 10056
int ans[1001], c[1001][1001];
int solve()
{
    c[0][0] = 1;
    int i, j;
    for (i = 1; i < 1001; ++i)
    {
        int s = 0;
        for (j = 1; j <= i; ++j)
        {
            // c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) * j % MOD;
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) * j;
            if (c[i][j] >= MOD)
                c[i][j] = c[i][j] % MOD;
            // s = (s + c[i][j]) % MOD;
            s += (c[i][j]);
            if (s >= MOD)
                s = s % MOD;
        }
        ans[i] = s;
    }
}
int main()
{
    int t, n, cas;
    solve();
    scanf("%d", &t);
    for (cas = 1; cas <= t; ++cas)
    {
        scanf("%d", &n);
        printf("Case %d: %d\n", cas, ans[n]);
    }
    return 0;
}