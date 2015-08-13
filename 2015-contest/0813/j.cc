#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define MOD 258280327
using namespace std;
const int mx = 1e5 + 5, mn = 10;
int dp[mx][mn][mn], c[mx];
inline int add(int x, int y) {
    int res = x + y;
    if (res >= 10)
        res = res % 10 + res / 10;
    return res;
}
int main() {
    int T, n, a, b, t1, t2;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &a, &b);
        for (int i = 1; i <= n; i++)
            scanf("%d", &c[i]);
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 10; j++)
                for (int k = 0; k < 10; k++) {
                    if (dp[i - 1][j][k] != 0) {
                        t1 = add(j, c[i]);
                        t2 = add(k, c[i]);
                        dp[i][j][t2] = (dp[i][j][t2] + dp[i - 1][j][k]) % MOD;
                        dp[i][t1][k] = (dp[i][t1][k] + dp[i - 1][j][k]) % MOD;
                    }
                }
        }
        printf("%d\n", (dp[n][a][b] + dp[n][a][0] + dp[n][0][b]) % MOD);
    }
    return 0;
}