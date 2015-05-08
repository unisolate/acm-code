#include <bits/stdc++.h>
#define MX 500050
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
using namespace std;
typedef long long ll;
typedef pair<int, int> seg;
ll sum[MX];
int pre[MX << 2], suf[MX << 2];
seg sub[MX << 2];
ll get(int l, int r) {
    return sum[r] - sum[l - 1];
}
ll get(seg s) {
    return get(s.first, s.second);
}
seg max(seg a, seg b) {
    if (get(a) != get(b)) return get(a) > get(b) ? a : b;
    return a < b ? a : b;
}
void pushUp(int l, int r, int n) {
    ll v1 = get(l, pre[n << 1]), v2 = get(l, pre[n << 1 | 1]);
    if (v1 == v2)
        pre[n] = min(pre[n << 1], pre[n << 1 | 1]);
    else pre[n] = v1 > v2 ? pre[n << 1] : pre[n << 1 | 1];
    v1 = get(suf[n << 1], r), v2 = get(suf[n << 1 | 1], r);
    if (v1 == v2)
        suf[n] = min(suf[n << 1], suf[n << 1 | 1]);
    else suf[n] = v1 > v2 ? suf[n << 1] : suf[n << 1 | 1];
    sub[n] = max(make_pair(suf[n << 1], pre[n << 1 | 1]),
                 max(sub[n << 1], sub[n << 1 | 1]));
}
void build(int l, int r, int n) {
    if (l == r) {
        pre[n] = suf[n] = l, sub[n] = make_pair(l, l);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushUp(l, r, n);
}
seg prefix(int L, int R, int l, int r, int n) {
    if (pre[n] <= R) return make_pair(l, pre[n]);
    int m = (l + r) >> 1;
    if (R <= m) return prefix(L, R, lson);
    seg ans = prefix(L, R, rson);
    ans.first = l;
    return max(ans, make_pair(l, pre[n << 1]));
}
seg suffix(int L, int R, int l, int r, int n) {
    if (suf[n] >= L) return make_pair(suf[n], r);
    int m = (l + r) >> 1;
    if (L > m) return suffix(L, R, rson);
    seg ans = suffix(L, R, lson);
    ans.second = r;
    return max(ans, make_pair(suf[n << 1 | 1], r));
}
seg query(int L, int R, int l, int r, int n) {
    if (L <= l && r <= R) return sub[n];
    int m = (l + r) >> 1;
    if (R <= m) return query(L, R, lson);
    if (L > m) return query(L, R, rson);
    return max(max(query(L, R, lson), query(L, R, rson)),
               make_pair(suffix(L, R, lson).first, prefix(L, R, rson).second));
}
int main() {
    int cas = 0, n, m, a, b;
    while (~scanf("%d%d", &n, &m)) {
        sum[0] = 0;
        for (int i = 0; i < n; ++i)
            scanf("%d", &a), sum[i + 1] = sum[i] + a;
        build(1, n, 1);
        printf("Case %d:\n", ++cas);
        while (m--) {
            scanf("%d%d", &a, &b);
            seg ans = query(a, b, 1, n, 1);
            printf("%d %d\n", ans.first, ans.second);
        }
    }
    return 0;
}