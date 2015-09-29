#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
const int mx = 100005;
int w[mx], u[mx], v[mx], p[mx], r[mx];
int n, m;
int cmp(const int i, const int j) {
    return w[i] < w[j];
}
int find(int x) {
    return p[x] == x ? p[x] : find(p[x]);
}
int kruskal() {
    int ans = 0;
    for (int i = 0; i < n; i++)
        p[i] = i;
    for (int i = 0; i < m; i++)
        r[i] = i;
    sort(r, r + m, cmp);
    for (int i = 0; i < m; i++) {
        int e = r[i];
        int x = find(u[e]);
        int y = find(v[e]);
        if (x != y) {
            ans = w[e];
            p[x] = y;
        }
    }
    return ans;
}
int main() {
    // freopen("t.in", "r", stdin);
    // freopen("t.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &u[i], &v[i], &w[i]);
            u[i]--;
            v[i]--;
        }
        int ans = kruskal();
        printf("%d\n", ans);
    }
    return 0;
}