#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MX 256
using namespace std;
typedef pair<int, int> P;
int n, m, a, b, c, d, f[MX][MX], u[MX][MX], v[MX][MX];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char p[MX][MX];
void bfs(int tx, int ty, int w[MX][MX]) {
    queue<P> q;
    q.push(make_pair(tx, ty));
    f[tx][ty] = 1;
    while (!q.empty()) {
        P t = q.front();
        q.pop();
        int x = t.first, y = t.second;
        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && p[xx][yy] != '#'
                    && p[xx][yy] != 'Y' && p[xx][yy] != 'M' && !f[xx][yy]) {
                f[xx][yy] = 1;
                w[xx][yy] = w[x][y] + 1;
                q.push(make_pair(xx, yy));
            }
        }
    }
}
int main() {
    while (~scanf("%d%d", &n, &m)) {
        memset(u, 0, sizeof(u));
        memset(v, 0, sizeof(v));
        for (int i = 0; i < n; ++i) {
            scanf("%s", p[i]);
            for (int j = 0; j < m; ++j) {
                if (p[i][j] == 'Y')
                    a = i, b = j;
                if (p[i][j] == 'M')
                    c = i, d = j;
            }
        }
        memset(f, 0, sizeof(f)), bfs(a, b, u);
        memset(f, 0, sizeof(f)), bfs(c, d, v);
        int k = MX * MX * MX;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (p[i][j] == '@' && u[i][j] && v[i][j])
                    k = min(k, u[i][j] + v[i][j]);
        printf("%d\n", 11 * k);
    }
    return 0;
}