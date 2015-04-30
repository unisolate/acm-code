#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, ans;
bool f[9][9];
int c(int s, int x, int y) {
    return s | (1 << (x * m + y));
}
int g(int s, int x, int y) {
    return 1 & (s >> (x * m + y));
}
bool v(int s, int x, int y) {
    bool z = false;
    for (int i = x - 1; i >= 0; --i) {
        if (g(s, i, y)) {
            if (z)
                return false;
            else z = true;
        } else if (f[i][y]) {
            if (z)
                break;
            else z = true;
        }
    }
    z = false;
    for (int j = y - 1; j >= 0; --j) {
        if (g(s, x, j)) {
            if (z)
                return false;
            else z = true;
        } else if (f[x][j]) {
            if (z)
                break;
            else z = true;
        }
    }
    return true;
}
void dfs(int s, int x, int y) {
    bool z = false;
    for (int i = x; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (i == x && j < y) continue;
            if (f[i][j]) continue;
            if (v(s, i, j)) {
                // printf("#%d %d\n", i, j);
                dfs(c(s, i, j), i + (j == m - 1 ? 1 : 0), j == m - 1 ? 0 : j + 1);
                z = true;
            }
        }
    if (!z) {
        int r = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                r += g(s, i, j);
        // printf("##%d\n", r);
        ans = max(ans, r);
    }
}
int main() {
    int q, x, y;
    while (~scanf("%d%d%d", &n, &m, &q)) {
        memset(f, false, sizeof(f));
        ans = 0;
        for (int i = 0; i < q; ++i) {
            scanf("%d%d", &x, &y);
            f[x][y] = true;
        }
        dfs(0, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}