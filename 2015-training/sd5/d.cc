#include <cstdio>
#include <cstring>
#include <algorithm>
#define MX 102400
#define ls l,m,n<<1
#define rs m+1,r,n<<1|1
#define lc n<<1
#define rc n<<1|1
using namespace std;
typedef long long ll;
ll sum[MX << 2], add[MX << 2], V;
bool se[MX << 2];
int L, R, N;
inline void up(int n) {
    sum[n] = sum[lc] + sum[rc];
}
void B(int l = 1, int r = N, int n = 1) {
    add[n] = 0;
    se[n] = false;
    if (l == r) {
        sum[n] = 0;
        return;
    }
    int m = (l + r) >> 1;
    B(ls), B(rs), up(n);
}
void down(int n, int m) {
    if (se[n]) {
        se[lc] = se[rc] = se[n];
        sum[lc] = sum[rc] = 0;
        se[n] = false;
        add[lc] = add[rc] = 0;
    }
    if (add[n]) {
        add[lc] += add[n];
        add[rc] += add[n];
        sum[lc] += add[n] * (m - (m >> 1));
        sum[rc] += add[n] * (m >> 1);
        add[n] = 0;
    }
}
void U(int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R) {
        add[n] += V, sum[n] += V * (r - l + 1);
        return;
    }
    down(n, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) U(ls);
    if (m < R) U(rs);
    up(n);
}
void S(int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R) {
        se[n] = true, add[n] = false, sum[n] = 0;
        return;
    }
    down(n, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) S(ls);
    if (m < R) S(rs);
    up(n);
}
ll Q(int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R) {
        return sum[n];
    }
    down(n, r - l + 1);
    ll ans = 0, m = (l + r) >> 1;
    if (L <= m) ans += Q(ls);
    if (m < R) ans += Q(rs);
    return ans;
}
int main() {
    int t, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &N, &m), B();
        ll ans = 0;
        int p = 0, q = 0;
        while (m--) {
            scanf("%d", &q);
            L = 1, R = N, V = q - p;
            U(), p = q;
            scanf("%d%d", &L, &R);
            ans += Q(), S();
        }
        printf("%lld\n", ans);
    }
    return 0;
}