#include <cstdio>
using namespace std;
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int main() {
    int m, n, k, x, y, cas = 0;
    while (scanf("%d%d", &m, &n) && m + n) {
        scanf("%d", &k);
        int s = 0;
        for (int i = 0; i < k; ++i) {
            scanf("%d%d", &x, &y);
            s |= (1 << (x * n + y));
        }
        int v = 1 << (m * n), ans = 0;
        for (int a = 0; a < v; ++a) {
            x = y = a;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    int c = 0;
                    for (k = 0; k < 8; ++k) {
                        if (x & (1 << (((i + dx[k] + m) % m) * n +
                                       (j + dy[k] + n) % n)))
                            ++c;
                    }
                    if (x & (1 << (i * n + j))) {
                        if (c != 2 && c != 3) {
                            y &= ~(1 << (i * n + j));
                        }
                    } else {
                        if (c == 3) {
                            y |= (1 << (i * n + j));
                        }
                    }
                }
            }
            if (y == s)
                ++ans;
        }
        printf("Case %d: ", ++cas);
        if (ans) {
            printf("%d possible ancestors.\n", ans);
        } else {
            puts("Garden of Eden.");
        }
    }
    return 0;
}