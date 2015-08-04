#include <cstdio>
#include <vector>
#include <algorithm>
#define MX 1024
using namespace std;
int n, d, a, b, x[MX], y[MX], p[MX];
vector<int> q[MX];
bool f[MX];
char o[9];
int F(int v) {
    return v == p[v] ? v : (p[v] = F(p[v]));
}
void U(int u, int v) {
    u = F(u), v = F(v);
    if (u == v) return;
    p[u] = v;
}
inline int A(int v) {
    return v > 0 ? v : -v;
}
inline int D(int u, int v) {
    return (x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]);
}
int main() {
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
        scanf("%d%d", x + i, y + i);
    }
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (A(x[i] - x[j]) > d || A(y[i] - y[j]) > d)
                continue;
            if (D(i, j) <= d * d) {
                q[i].push_back(j);
                q[j].push_back(i);
            }
        }
    }
    while (~scanf("%s", o)) {
        if (o[0] == 'O') {
            scanf("%d", &a);
            f[a] = true;
            for (int i = 0; i < q[a].size(); ++i)
                if (f[q[a][i]]) {
                    U(q[a][i], a);
                }
        } else {
            scanf("%d%d", &a, &b);
            if (F(a) == F(b))
                puts("SUCCESS");
            else puts("FAIL");
        }
    }
    return 0;
}