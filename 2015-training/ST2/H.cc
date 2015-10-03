#include <cstdio>
#define MX 111111
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define lc n<<1
#define rc n<<1|1
using namespace std;
typedef long long ll;
ll sum[MX << 2], add[MX << 2], v;
int L, R, N;
inline void up(int n) {
    sum[n] = sum[lc] + sum[rc];
}
void B(int l = 1, int r = N, int n = 1) {
    add[n] = 0;
    if (l == r) {
        scanf("%lld", &sum[n]);
        return;
    }
    int m = l + r >> 1;
    B(lson), B(rson), up(n);
}
void down(int n, int m) {
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
        add[n] += v, sum[n] += v * (r - l + 1);
        return;
    }
    down(n, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) U(lson);
    if (m < R) U(rson);
    up(n);
}
ll Q(int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R)
        return sum[n];
    down(n, r - l + 1);
    ll ans = 0;
    int m = l + r >> 1;
    if (L <= m) ans += Q(lson);
    if (m < R) ans += Q(rson);
    return ans;
}
int main() {
    int q;
    char op[11];
    scanf("%d%d", &N, &q), B();
    while (q--) {
        scanf("%s%d%d", op, &L, &R);
        if (op[0] == 'C')
            scanf("%lld", &v), U();
        else printf("%lld\n", Q());
    }
    return 0;
}