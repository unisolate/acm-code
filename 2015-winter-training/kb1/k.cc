#include <cstdio>
#include <queue>
using namespace std;
int m[5][5], f[5][5], p[5][5];
int a[] = {1, 0, -1, 0};
int b[] = {0, 1, 0, -1};
typedef pair<int, int> P;
bool c(int n) {
    return (n >= 0 && n < 5);
}
void d(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int u = x + a[i], v = y + b[i];
        if (c(u) && c(v) && !m[u][v] && p[u][v] == p[x][y] - 1)
            d(u, v);
    }
    printf("(%d, %d)\n", x, y);
}
int main() {
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            scanf("%d", &m[i][j]);
    queue<P> q;
    q.push(make_pair(0, 0));
    f[0][0] = 1;
    while (!q.empty()) {
        P t = q.front();
        q.pop();
        int x = t.first, y = t.second;
        // printf("%d %d\n", x, y);
        if (x == 4 && y == 4)
            break;
        for (int i = 0; i < 4; ++i) {
            int u = x + a[i], v = y + b[i];
            if (c(u) && c(v) && !m[u][v] && !f[u][v]) {
                f[u][v] = 1;
                p[u][v] = p[x][y] + 1;
                q.push(make_pair(u, v));
            }
        }
    }
    d(4, 4);
    return 0;
}