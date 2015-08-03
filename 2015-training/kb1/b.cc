#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int l, r, c, x, y, z, tx, ty, tz;
int f[42][42][42];
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
char p[42][42][42];
typedef pair<int, pair<int, int> > pr;
void bfs() {
    queue<pr> q;
    q.push(make_pair(x, make_pair(y, z)));
    while (!q.empty()) {
        pr v = q.front();
        q.pop();
        x = v.first, y = v.second.first, z = v.second.second;
        for (int i = 0; i < 6; ++i) {
            tx = x + dx[i], ty = y + dy[i], tz = z + dz[i];
            if (tx < 0 || tx >= l || ty < 0 || ty >= r || tz < 0 || tz >= c
                    || f[tx][ty][tz])
                continue;
            if (p[tx][ty][tz] == 'E') {
                printf("Escaped in %d minute(s).\n", f[x][y][z] + 1);
                return;
            } else if (p[tx][ty][tz] == '.') {
                q.push(make_pair(tx, make_pair(ty, tz)));
                f[tx][ty][tz] = f[x][y][z] + 1;
            }
        }
    }
    puts("Trapped!");
}
int main() {
    while (scanf("%d%d%d", &l, &r, &c) && l) {
        for (int i = 0; i < l; ++i)
            for (int j = 0; j < r; ++j) {
                scanf("%s", p[i][j]);
                for (int k = 0; k < c; ++k)
                    if (p[i][j][k] == 'S')
                        x = i, y = j, z = k;
            }
        memset(f, 0, sizeof(f));
        bfs();
    }
    return 0;
}