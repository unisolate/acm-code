#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
const int mx = 1005, inf = 0x3f3f3f3f;
char chr[mx];
int dp[mx];
bool jud[mx][mx];
int main() {
    // freopen("t.in", "r", stdin);
    // freopen("t.out", "w", stdout);
    int T, n, k, l, t;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%s", &n, &k, chr + 1);
        memset(dp, 0x3f, sizeof(dp));
        memset(jud, false, sizeof(jud));
        l = strlen(chr + 1);
        for (int i = 1; i <= l; i++) {
            t = chr[i] - '0';
            jud[i][i] = true;
            for (int j = i + 1; j <= l; j++) {
                t = t ^ 1;
                if (jud[i][j - 1] && chr[j] == t + '0')
                    jud[i][j] = true;
                else
                    jud[i][j] = false;
            }
        }
        for (int i = 1; i <= l; i++)
            jud[i][i] = false;
        dp[0] = 0;
        for (int i = 1; i <= l; i++) {
            for (int j = i; j <= min(l, i + k - 1); j++) {
                if (!jud[i][j]) {
                    dp[j] = min(dp[j], dp[i - 1] + 1);
                }
            }
        }
        // for (int i = 0; i <= l; i++) {
        //     cout << i << " " << dp[i] << endl;
        // }
        printf("%d\n", dp[l] - 1);
    }
    return 0;
}