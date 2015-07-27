#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#define MX 64
using namespace std;
int t, n, m, ans;
int x[MX], y[MX], a[MX], b[MX], d[MX];
void dfs(int e) {
    if (e == m) {
        for (int i = 1; i <= n; ++i)
            if (x[i] != y[i])
                return;
        ++ans;
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (abs(x[i] - y[i]) > d[i])
            return;
    }
    --d[a[e]];
    --d[b[e]];
    ++x[a[e]];
    ++x[b[e]];
    dfs(e + 1);
    --x[a[e]];
    --x[b[e]];
    ++y[a[e]];
    ++y[b[e]];
    dfs(e + 1);
    --y[a[e]];
    --y[b[e]];
    ++d[a[e]];
    ++d[b[e]];
}
int main() {
    scanf("%d", &t);
    while (t--) {
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        memset(d, 0, sizeof(d));
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &a[i], &b[i]);
            ++d[a[i]];
            ++d[b[i]];
        }
        ans = 0;
        dfs(0);
        printf("%d\n", ans);
    }
    return 0;
}