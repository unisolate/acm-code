#include <cstdio>
#include <cstring>
#include <queue>
#define MX 1024
#define INF 10240000
using namespace std;
int c, m, n, jx, jy, s[MX][MX], f[MX][MX];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char p[MX][MX];
typedef struct {
    int x, y, v;
} S;
void bfs() {
    queue<S> q;
    S t;
    t.x = jx, t.y = jy, t.v = 0;
    q.push(t);
    while (!q.empty()) {
        t = q.front();
        int tx = t.x, ty = t.y, tv = t.v;
        if (tx == 0 || tx == m - 1 || ty == 0 || ty == n - 1) {
            printf("%d\n", tv + 1);
            return;
        }
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int xx = tx + dx[i], yy = ty + dy[i];
            if (xx >= 0 && xx < m && yy >= 0 && yy < n && p[xx][yy] != '#'
                    && !f[xx][yy] && s[xx][yy] > tv + 1) {
                f[xx][yy] = 1;
                t.x = xx, t.y = yy, t.v = tv + 1;
                q.push(t);
            }
        }
    }
    puts("IMPOSSIBLE");
}
// void dfs(int x, int y, int v) {
//     for (int i = 0; i < 4; ++i) {
//         int xx = x + dx[i], yy = y + dy[i];
//         if (xx >= 0 && xx < m && yy >= 0 && yy < n && p[xx][yy] != '#'
//                 && s[xx][yy] > v + 1) {
//             s[xx][yy] = v + 1;
//             dfs(xx, yy, v + 1);
//         }
//     }
// }
void mark() {
    queue<S> q;
    S t;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (p[i][j] == 'F') {
                s[i][j] = 0;
                t.x = i, t.y = j, t.v = 0;
                q.push(t);
            }
    while (!q.empty()) {
        t = q.front();
        int tx = t.x, ty = t.y, tv = t.v;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int xx = tx + dx[i], yy = ty + dy[i];
            if (xx >= 0 && xx < m && yy >= 0 && yy < n && p[xx][yy] != '#'
                    && s[xx][yy] > tv + 1) {
                s[xx][yy] = tv + 1;
                t.x = xx, t.y = yy, t.v = tv + 1;
                q.push(t);
            }
        }
    }
}
int main() {
    scanf("%d", &c);
    while (c--) {
        scanf("%d%d", &m, &n);
        for (int i = 0; i < m; ++i) {
            scanf("%s", p[i]);
            for (int j = 0; j < n; ++j) {
                s[i][j] = INF;
                if (p[i][j] == 'J')
                    jx = i, jy = j;
            }
        }
        memset(f, 0, sizeof(f));
        // for (int i = 0; i < m; ++i)
        //     for (int j = 0; j < n; ++j)
        //         if (p[i][j] == 'F')
        //             s[i][j] = 0, dfs(i, j, 0);
        mark();
        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < m; ++j)
        //         printf("%d ", s[i][j]);
        //     puts("");
        // }
        bfs();
    }
    return 0;
}