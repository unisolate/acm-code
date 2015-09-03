#include <cstdio>
#include <cstring>
#define MX 1024
using namespace std;
int n, m, k, x, y, p[MX][MX];
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int ex[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int ey[8] = {2, -2, 1, -1, 2, -2, 1, -1};
inline bool v(int i, int j) {
    return i >= 0 && i <= n && j >= 0 && j <= m;
}
int main() {
    int cas = 0;
    while (scanf("%d%d", &n, &m) && n + m) {
        memset(p, 0, sizeof(p));
        scanf("%d", &k);
        for (int i = 0; i < k; ++i) {
            scanf("%d%d", &x, &y);
            p[x][y] = 1;
        }
        scanf("%d", &k);
        for (int i = 0; i < k; ++i) {
            scanf("%d%d", &x, &y);
            p[x][y] = 2;
        }
        scanf("%d", &k);
        for (int i = 0; i < k; ++i) {
            scanf("%d%d", &x, &y);
            p[x][y] = 3;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (p[i][j] == 1) {
                    for (int l = 0; l < 8; ++l) {
                        x = i + dx[l], y = j + dy[l];
                        while (v(x, y)) {
                            if (p[x][y] > 0)
                                break;
                            p[x][y] = -1;
                            x += dx[l];
                            y += dy[l];
                        }
                    }
                } else if (p[i][j] == 2) {
                    for (int l = 0; l < 8; ++l) {
                        if (v(i + ex[l], j + ey[l]) &&
                            p[i + ex[l]][j + ey[l]] <= 0) {
                            p[i + ex[l]][j + ey[l]] = -1;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (p[i][j] == 0) {
                    ++ans;
                }
            }
        }
        printf("Board %d has %d safe squares.\n", ++cas, ans);
    }
    return 0;
}