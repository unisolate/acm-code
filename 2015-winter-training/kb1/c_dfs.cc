#include <cstdio>
#include <cstring>
#include <algorithm>
#define MX 102400
#define INF 0x7f7f7f7f
using namespace std;
int n, k, t, u, p[MX];
int dfs(int v) {
    if (v <= 0)
        return INF;
    printf("#%d %d\n", v, p[v]);
    if (p[v] != INF)
        return p[v];
    // if (v < k) {
    //     p[v] = min(p[v], 1 + dfs(2 * v));
    //     p[v] = min(p[v], 1 + dfs(1 + v));
    // }
    // p[v] = min(p[v], 1 + dfs(v - 1));
    if (v > k)
        p[v] = min(p[v], v - k);
    else {
        // p[v] = min(p[v], 1 + dfs(v + 1));
        // if (v * 2 >= k) {
        //     p[v] = min(p[v], 1 + dfs(v * 2));
        //     p[v] = min(p[v], 1 + dfs(v - 1));
        // } else {
        //     t = 0, u = v;
        //     while (u * 2 < k)
        //         u *= 2, ++t;
        //     p[v] = min(p[v], t + dfs(u));
        // }
        t = 0;
        while (v * 2 < k)
            v *= 2, ++t;
        // p[v] = min(p[v], t + dfs(v));
        p[v] = min(p[v], t + dfs(v + 1));
        p[v] = min(p[v], t + dfs(v - 1));
    }
    return p[v];
}
int main() {
    while (~scanf("%d%d", &n, &k)) {
        if (n < k) {
            memset(p, INF, sizeof(p));
            p[k] = 0;
            printf("%d\n", dfs(n));
        } else printf("%d\n", n - k);
    }
    return 0;
}