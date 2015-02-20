#include <cstdio>
#include <cstring>
#define MOD 10056
using namespace std;
int ans[1001], c[1001][1001];
int solve()
{
    c[0][0] = 1;
    for (int i = 1; i < 1001; ++i)
    {
        int s = 0;
        for (int j = 1; j <= i; ++j)
        {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) * j % MOD;
            s = (s + c[i][j]) % MOD;
        }
        ans[i] = s;
    }
}
int main()
{
    int t, n;
    solve();
    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas)
    {
        scanf("%d", &n);
        printf("Case %d: %d\n", cas, ans[n]);
    }
    return 0;
}