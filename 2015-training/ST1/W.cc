#include <cstdio>
#include <algorithm>
#define MX 102400
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define lc n<<1
#define rc n<<1|1
using namespace std;
int N, X, V, num[MX], mm[MX << 2], lm[MX << 2], rm[MX << 2];
void B(int l = 1, int r = N, int n = 1) {
    if (l == r) {
        scanf("%d", &num[l]);
        lm[n] = rm[n] = mm[n] = 1;
        return;
    }
    int m = (l + r) >> 1, k = r - l + 1;
    B(lson), B(rson);
    lm[n] = lm[lc];
    if (lm[lc] == k - (k >> 1) && num[m] < num[m + 1])
        lm[n] += lm[rc];
    rm[n] = rm[rc];
    if (rm[rc] == (k >> 1) && num[m] < num[m + 1])
        rm[n] += rm[lc];
    mm[n] = max(mm[lc], mm[rc]);
    if (num[m] < num[m + 1])
        mm[n] = max(mm[n], rm[lc] + lm[rc]);
}
void U(int l = 1, int r = N, int n = 1) {
    if (l == r) {
        num[l] = V;
        return;
    }
    int m = (l + r) >> 1, k = r - l + 1;
    if (X <= m) U(lson);
    else U(rson);
    lm[n] = lm[lc];
    if (lm[lc] == k - (k >> 1) && num[m] < num[m + 1])
        lm[n] += lm[rc];
    rm[n] = rm[rc];
    if (rm[rc] == (k >> 1) && num[m] < num[m + 1])
        rm[n] += rm[lc];
    mm[n] = max(mm[lc], mm[rc]);
    if (num[m] < num[m + 1])
        mm[n] = max(mm[n], rm[lc] + lm[rc]);
}
int QL(int L, int R, int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R)
        return lm[n];
    int m = (l + r) >> 1;
    if (L > m) return QL(L, R, rson);
    if (R <= m) return QL(L, R, lson);
    int ans = QL(L, m, lson), k = m - L + 1;
    if (ans == k && num[m] < num[m + 1])
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
    if (ans == k && num[m] < num[m + 1])
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
    if (num[m] < num[m + 1])
        ans = max(ans, QR(L, m, lson) + QL(m + 1, R, rson));
    return ans;
}
int main() {
    int t, m, L, R;
    char o[9];
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &N, &m), B();
        while (m--) {
            scanf("%s", o);
            if (o[0] == 'Q') {
                scanf("%d%d", &L, &R), printf("%d\n", Q(L + 1, R + 1));
            } else {
                scanf("%d%d", &X, &V), ++X, U();
            }
        }
    }
    return 0;
}