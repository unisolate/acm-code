#include <cstdio>
#include <cstring>
#include <algorithm>
#define ls l, m, n << 1          // lson
#define rs m + 1, r, n << 1 | 1  // rson
#define lc n << 1                // lchild
#define rc n << 1 | 1            // rchild
#define MX 2048
using namespace std;
struct seg {
    double l, r, p;
    int d;
    seg() {
    }
    seg(double _l, double _r, double _p, int _d) {
        l = _l, r = _r, p = _p, d = _d;
    }
} x[MX];
bool cmp(seg a, seg b) {
    return a.p < b.p;
}
double a, b, c, d, y[MX], sum[MX << 2];
int L, R, V, N, add[MX << 2];
void U(int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R) {
        add[n] += V;
        // printf("#%d %d %d\n", l, r, add[n]);
        sum[n] = add[n] ? (y[r + 1] - y[l]) : (l == r ? 0 : sum[lc] + sum[rc]);
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m)
        U(ls);
    if (m < R)
        U(rs);
    sum[n] = add[n] ? (y[r + 1] - y[l]) : (l == r ? 0 : sum[lc] + sum[rc]);
}
int main() {
    int n, k, cas = 0;
    while (scanf("%d", &n) && n) {
        n *= 2;
        for (int i = 1; i <= n; i += 2) {
            scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
            x[i] = seg(b, d, a, 1);
            x[i + 1] = seg(b, d, c, -1);
            y[i] = b;
            y[i + 1] = d;
        }
        sort(x + 1, x + n + 1, cmp);
        sort(y + 1, y + n + 1);
        N = unique(y + 1, y + n + 1) - y - 1;
        memset(sum, 0, sizeof(sum));
        memset(add, 0, sizeof(add));
        double ans = 0.0;
        for (int i = 1; i < n; ++i) {
            L = lower_bound(y + 1, y + N + 1, x[i].l) - y;
            R = lower_bound(y + 1, y + N + 1, x[i].r) - y - 1;
            V = x[i].d;
            if (L <= R)
                U();
            ans += sum[1] * (x[i + 1].p - x[i].p);
            // printf("%.2lf\n", sum[1]);
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n", ++cas, ans);
    }
    return 0;
}