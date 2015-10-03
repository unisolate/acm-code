#include <cstdio>
#include <algorithm>
#define MX 102400
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define lc n<<1
#define rc n<<1|1
using namespace std;
int N, V, num[MX], mm[MX << 2], lm[MX << 2], rm[MX << 2];
int abs(int x, int y) {
    return x - y < 0 ? y - x : x - y;
}
void B(int l = 1, int r = N, int n = 1) {
    if (l == r) {
        scanf("%d", &num[l]);
        lm[n] = rm[n] = mm[n] = 1;
        return;
    }
    int m = (l + r) >> 1, k = r - l + 1;
    B(lson), B(rson);
    lm[n] = lm[lc];
    if (lm[lc] == k - (k >> 1) && abs(num[m], num[m + 1]) <= V)
        lm[n] += lm[rc];
    rm[n] = rm[rc];
    if (rm[rc] == (k >> 1) && abs(num[m], num[m + 1]) <= V)
        rm[n] += rm[lc];
    mm[n] = max(mm[lc], mm[rc]);
    if (abs(num[m], num[m + 1]) <= V)
        mm[n] = max(mm[n], rm[lc] + lm[rc]);
}
int QL(int L, int R, int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R)
        return lm[n];
    int m = (l + r) >> 1;
    if (L > m) return QL(L, R, rson);
    if (R <= m) return QL(L, R, lson);
    int ans = QL(L, m, lson), k = m - L + 1;
    if (ans == k && abs(num[m], num[m + 1]) <= V)
        ans += QL(m + 1, R, rson);
    return ans;
}
int QR(int L, int R, int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R)
        return rm[n];
    int m = (l + r) >> 1;
    if (L > m) return QR(L, R, rson);
    if (R <= m) return QR(L, R, lson);
    int ans = QR(m + 1, R, rson), k = R - m;
    if (ans == k && abs(num[m], num[m + 1]) <= V)
        ans += QR(L, m, lson);
    return ans;
}
int Q(int L, int R, int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R)
        return mm[n];
    int m = (l + r) >> 1;
    if (L > m) return Q(L, R, rson);
    if (R <= m) return Q(L, R, lson);
    int ans = max(Q(L, m, lson), Q(m + 1, R, rson));
    if (abs(num[m], num[m + 1]) <= V)
        ans = max(ans, QR(L, m, lson) + QL(m + 1, R, rson));
    return ans;
}
int main() {
    while (~scanf("%d%d", &N, &V)) {
        B();
        printf("%d\n", Q(1, N));
    }
    return 0;
}