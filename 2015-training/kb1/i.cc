#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x7f7f7f7f
using namespace std;
int cas, T, n, m, ans, v[99][99];
char p[99][99];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void dfs(int x, int y, int u) {
    for (int i = 0; i < 4; ++i) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && p[xx][yy] == '#'
                && u + 1 < v[xx][yy]) {
            v[xx][yy] = u + 1;
            dfs(xx, yy, u + 1);
        }
    }
}
int cal() {
    int r = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (p[i][j] == '#') {
                if (v[i][j] == INF)
                    return INF;
                r = max(r, v[i][j]);
            }
        }
    return r;
}
int main() {
    scanf("%d", &T);
    while (T--) {
        ans = INF;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
            scanf("%s", p[i]);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (p[i][j] == '#') {
                    bool flag = false;
                    for (int k = 0; k < n; ++k)
                        for (int l = 0; l < m; ++l) {
                            if (k == i && l == j)
                                flag = true;
                            if (flag && p[k][l] == '#') {
                                memset(v, INF, sizeof(v));
                                v[i][j] = 0;
                                dfs(i, j, 0);
                                v[k][l] = 0;
                                dfs(k, l, 0);
                                ans = min(ans, cal());
                            }
                        }
                }
        printf("Case %d: %d\n", ++cas, ans == INF ? -1 : ans);
    }
    return 0;
}