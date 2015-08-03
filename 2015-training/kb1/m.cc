#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MX 128
using namespace std;
typedef struct {
    int x, y, z, p;
} S;
int s, n, m, k, f[MX][MX][MX];
void bfs() {
    queue<S> q;
    S t;
    t.x = 0, t.y = 0, t.z = s, t.p = 0;
    f[0][0][s] = 1;
    q.push(t);
    while (!q.empty()) {
        t = q.front();
        int u = t.x, v = t.y, w = t.z, a = t.p;
        if ((u == s / 2 && u == v) || (v == s / 2 && v == w) || (w == s / 2
                && w == u)) {
            printf("%d\n", t.p);
            return;
        }
        if (u) {
            if (v < m) {
                k = min(u, m - v);
                if (!f[u - k][v + k][w]) {
                    f[u - k][v + k][w] = 1;
                    t.x = u - k, t.y = v + k, t.z = w, t.p = a + 1;
                    q.push(t);
                }
            }
            if (!f[0][v][w + u]) {
                f[0][v][w + u] = 1;
                t.x = 0, t.y = v, t.z = w + u, t.p = a + 1;
                q.push(t);
            }
        }
        if (v) {
            if (u < n) {
                k = min(v, n - u);
                if (!f[u + k][v - k][w]) {
                    f[u + k][v - k][w] = 1;
                    t.x = u + k, t.y = v - k, t.z = w, t.p = a + 1;
                    q.push(t);
                }
            }
            if (!f[u][0][w + v]) {
                f[u][0][w + v] = 1;
                t.x = u, t.y = 0, t.z = w + v, t.p = a + 1;
                q.push(t);
            }
        }
        if (w) {
            if (v < m) {
                k = min(w, m - v);
                if (!f[u][v + k][w - k]) {
                    f[u][v + k][w - k] = 1;
                    t.x = u, t.y = v + k, t.z = w - k, t.p = a + 1;
                    q.push(t);
                }
            }
            if (u < n) {
                k = min(w, n - u);
                if (!f[u + k][v][w - k]) {
                    f[u + k][v][w - k] = 1;
                    t.x = u + k, t.y = v, t.z = w - k, t.p = a + 1;
                    q.push(t);
                }
            }
        }
        q.pop();
    }
    puts("NO");
}
int main() {
    while (scanf("%d%d%d", &s, &n, &m), s) {
        if (s % 2)
            puts("NO");
        else
            memset(f, 0, sizeof(f)), bfs();
    }
    return 0;
}