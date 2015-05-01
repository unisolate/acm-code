/*
Interval Tree ( Segment Tree )
Unommented & Compressed Version
By Uni, 2014/8/8
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MX 102400
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define lc n<<1
#define rc n<<1|1
using namespace std;
long long sum[MX << 2], add[MX << 2], se[MX << 2];
int L, R, N;
long long v;
inline void up(int n) {
    sum[n] = sum[lc] + sum[rc];
}
void B(int l = 1, int r = N, int n = 1) {
    add[n] = se[n] = 0;
    if (l == r) {
        sum[n] = 0;
        return;
    }
    int m = (l + r) >> 1;
    B(lson), B(rson), up(n);
}
void dow(int n) {
    add[lc] = add[rc] = -1;
    sum[lc] = sum[rc] = 0;
    add[n] = 0;
}
void down(int n, int m) {
    if (add[n]) {
        add[lc] += add[n];
        add[rc] += add[n];
        sum[lc] += add[n] * (m - (m >> 1));
        sum[rc] += add[n] * (m >> 1);
        add[n] = 0;
    }
    if (~se[n]) {
        se[lc] = se[rc] = se[n];
        se[n] = -1;
        se[lc] = se[rc] = 0;
    }
}
// Prepare: L, R, v
void U(int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R) {
        add[n] += v, sum[n] += v * (r - l + 1);
        return;
    }
    down(n, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) U(lson);
    if (m < R) U(rson);
    up(n);
}
// Prepare: L, R
void S(int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R) {
        se[n] = 0, sum[n] = 0;
        return;
    }
    down(n, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) S(lson);
    if (m < R) S(rson);
    up(n);
}
// Prepare: L, R
long long Q(int l = 1, int r = N, int n = 1) {
    if (~se[n]) {
        return se[n] * (min(r, R) - max(l, L) + 1);
    }
    if (L <= l && r <= R) {
        return sum[n];
    }
    down(n, r - l + 1);
    long long ans = 0, m = (l + r) >> 1;
    if (L <= m) ans += Q(lson);
    if (m < R) ans += Q(rson);
    return ans;
}
int main() {
    int t, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &N, &m);
        B();
        long long ans = 0;
        int p = 0, q = 0;
        while (m--) {
            scanf("%d", &q);
            L = 1, R = N, v = q - p;
            U();
            p = q;
            scanf("%d%d", &L, &R);
            ans += Q();
            v = 0;
            S();
        }
        printf("%lld\n", ans);
    }
    return 0;
}