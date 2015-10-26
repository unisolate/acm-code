#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mx = int(1e4) + 5;
const int mxm = int(1e5) + 5;

struct edge {
    int from, to, cost;
    void read() {
        scanf("%d%d%d", &from, &to, &cost);
    }
    bool operator<(const edge &b) const {
        return cost < b.cost;
    }
} e[mxm];

int fa[mx], n, m;
int find(int x) {
    return ~fa[x] ? fa[x] = find(fa[x]) : x;
}

int Kruskal() {
    sort(e, e + m);
    memset(fa, -1, sizeof(fa));
    int sum = 0, cnt = 0;
    for (int i = 0; i < m; ++i) {
        int fau = find(e[i].from), fav = find(e[i].to);
        if (fau != fav)
            fa[fau] = fav, sum += e[i].cost, ++cnt;
    }
    return cnt == n - 1 ? sum : -1;
}

#include <iostream>
#include <algorithm>
#define MAXN 11111
using namespace std;
int w[MAXN], p[MAXN], r[MAXN], u[MAXN], v[MAXN];
int cmp(int i, int j) {
    return w[i] < w[j];
}
int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}
void kruskal(int n, int m) {
    int ans = 0;
    for (int i = 0; i <= n; ++i)
        p[i] = i;
    for (int i = 0; i <= m; ++i)
        r[i] = i;
    sort(r, r + m, cmp);
    for (int i = 0; i < m; ++i) {
        int e = r[i], x = find(u[e]), y = find(v[e]);
        if (x != y) {
            ans += w[e];
            p[x] = y;
        }
    }
    cout << ans << endl;
}
int main() {
    int n;
    while (cin >> n && n) {
        int m = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> w[m];
                u[m] = i;
                v[m] = j;
                ++m;
            }
        }
        kruskal(n, m);
    }
    return 0;
}