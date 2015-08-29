#include <cstdio>
#define MX 4444
#define INF 1000000000
using namespace std;
int a, b, x[MX];
bool v[MX][MX];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        v[a][b] = true;
        v[b][a] = true;
        x[a]++;
        x[b]++;
    }
    int ans = INF;
    for (int i = 1; i <= n; ++i) {
        if (x[i] >= 2) {
            for (int j = i + 1; j <= n; ++j) {
                if (x[j] >= 2 && v[i][j]) {
                    for (int k = j + 1; k <= n; ++k) {
                        if (x[k] >= 2 && v[j][k] && v[i][k]) {
                            if (ans > x[i] + x[j] + x[k]) {
                                ans = x[i] + x[j] + x[k];
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", ans == INF ? -1 : ans - 6);
    return 0;
}