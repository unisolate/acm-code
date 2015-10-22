/* 22724 KB 1313 ms */
#include <cstdio>
#include <algorithm>
#define MX 100010
using namespace std;
struct Node {
    int l, r, v;
} t[MX * 20];
struct P {
    int v, i;
} p[MX];
bool cmp(P a, P b) {
    return a.v < b.v;
}
int n, cnt, pos[MX], root[MX];
void U(int v, int &x, int l = 1, int r = n) {
    t[cnt++] = t[x];
    x = cnt - 1;
    ++t[x].v;
    if (l == r) {
        return;
    }
    int m = (l + r) >> 1;
    if (v <= m) {
        U(v, t[x].l, l, m);
    } else {
        U(v, t[x].r, m + 1, r);
    }
}
int Q(int L, int R, int k, int l = 1, int r = n) {
    if (l == r) {
        return l;
    }
    int v = t[t[R].l].v - t[t[L].l].v;
    int m = (l + r) >> 1;
    if (k <= v) {
        return Q(t[L].l, t[R].l, k, l, m);
    }
    return Q(t[L].r, t[R].r, k - v, m + 1, r);
}
int main() {
    int m;
    t[0].l = t[0].r = t[0].v = root[0] = 0;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &p[i].v);
            p[i].i = i;
        }
        sort(p + 1, p + n + 1, cmp);
        for (int i = 1; i <= n; ++i) {
            pos[p[i].i] = i;
        }
        cnt = 1;
        for (int i = 1; i <= n; ++i) {
            root[i] = root[i - 1];
            U(pos[i], root[i]);
        }
        while (m--) {
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k);
            printf("%d\n", p[Q(root[l - 1], root[r], k)].v);
        }
    }
    return 0;
}