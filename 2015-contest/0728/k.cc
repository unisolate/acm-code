#include <cstdio>
#include <cstring>
#define MX 128
using namespace std;
int n, g[MX][MX], v[MX];
int dfs(int x) {
    if (v[x] != -1) return v[x];
    int c = 0;
    for (int i = 1; i <= n; ++i) {
        if (g[x][i])
            c += 1 + dfs(i);
    }
    return v[x] = c;
}
int main() {
    int k, a, b;
    while (~scanf("%d%d", &n, &k)) {
        memset(g, 0, sizeof(g));
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &a, &b);
            g[a][b] = 1;
            v[i] = -1;
        }
        v[n] = -1;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            // printf("%d\n", dfs(i));
            if (dfs(i) == k)
                ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}