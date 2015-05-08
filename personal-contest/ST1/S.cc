#include <cstdio>
#include <algorithm>

#define MX 102400
#define ls l,m,n<<1     // lson
#define rs m+1,r,n<<1|1 // rson
#define lc n<<1         // lchild
#define rc n<<1|1       // rchild

using namespace std;

int num[MX], sum[MX << 2], mm[MX << 2], lm[MX << 2], rm[MX << 2], add[MX << 2],
    inv[MX << 2];
int N, L, R, V;

inline void flip(int n) {
    if (inv[n] % 2) ++inv[n];
}

inline void up(int n) {
    sum[n] = sum[lc] + sum[rc];
}

void down(int n, int m) {
    if (add[n] != -1) {
        add[lc] = add[rc] = add[n];
        flip(lc), flip(rc);
        sum[lc] = add[n] * (m - (m >> 1));
        sum[rc] = add[n] * (m >> 1);
        add[n] = -1;
    }
    if (inv[n] && inv[n] % 2) {
        ++inv[lc];
        ++inv[rc];
        sum[lc] = (m - (m >> 1)) - sum[lc];
        sum[rc] = (m >> 1) - sum[rc];
        ++inv[n];
    }
}

void B(int l = 1, int r = N, int n = 1) {
    add[n] = -1, inv[n] = 0;
    if (l == r) {
        scanf("%d", &num[l]);
        sum[n] = num[l];
        if (num[l])
            lm[n] = rm[n] = mm[n] = 1;
        return;
    }
    int m = (l + r) >> 1, k = r - l + 1;
    B(ls), B(rs), up(n);
    bool f = num[m] && num[m] == num[m + 1];
    lm[n] = lm[lc];
    if (lm[lc] == k - (k >> 1) && f)
        lm[n] += lm[rc];
    rm[n] = rm[rc];
    if (rm[rc] == (k >> 1) && f)
        rm[n] += rm[lc];
    mm[n] = max(mm[lc], mm[rc]);
    if (f)
        mm[n] = max(mm[n], rm[lc] + lm[rc]);
}

void U(int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R) {
        add[n] = V;
        sum[n] = V * (r - l + 1);
        flip(n);
        return;
    }
    down(n, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) U(ls);
    if (m < R) U(rs);
    up(n);
}

void I(int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R) {
        ++inv[n];
        sum[n] = r - l + 1 - sum[n];
        return;
    }
    down(n, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) I(ls);
    if (m < R) I(rs);
    up(n);
}

int Q(int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R)
        return sum[n];
    down(n, r - l + 1);
    int m = (l + r) >> 1, ans = 0;
    if (L <= m) ans += Q(ls);
    if (m < R) ans += Q(rs);
    up(n);
    return ans;
}

// void M(int l = 1, int r = N, int n = 1) {
//     if (l == r) {
//         num[l] = sum[n];
//         if (num[l])
//             lm[n] = rm[n] = mm[n] = 1;
//         return;
//     }
//     down(n, r - l + 1);
//     int m = (l + r) >> 1, k = r - l + 1;
//     M(ls), M(rs), up(n);
//     bool f = num[m] && num[m] == num[m + 1];
//     lm[n] = lm[lc];
//     if (lm[lc] == k - (k >> 1) && f)
//         lm[n] += lm[rc];
//     rm[n] = rm[rc];
//     if (rm[rc] == (k >> 1) && f)
//         rm[n] += rm[lc];
//     mm[n] = max(mm[lc], mm[rc]);
//     if (f)
//         mm[n] = max(mm[n], rm[lc] + lm[rc]);
// }

int QL(int ll, int rr, int l = 1, int r = N, int n = 1) {
    if (ll <= l && r <= rr)
        return lm[n];
    int m = (l + r) >> 1;
    if (ll > m) return QL(ll, rr, rs);
    if (rr <= m) return QL(ll, rr, ls);
    int ans = QL(ll, m, ls), k = m - ll + 1;
    if (ans == k && num[m] && num[m] == num[m + 1])
        ans += QL(m + 1, rr, rs);
    return ans;
}

int QR(int ll, int rr, int l = 1, int r = N, int n = 1) {
    if (ll <= l && r <= rr)
        return rm[n];
    int m = (l + r) >> 1;
    if (ll > m) return QR(ll, rr, rs);
    if (rr <= m) return QR(ll, rr, ls);
    int ans = QR(m + 1, rr, rs), k = rr - m;
    if (ans == k && num[m] && num[m] == num[m + 1])
        ans += QR(ll, m, ls);
    return ans;
}

int QM(int ll, int rr, int l = 1, int r = N, int n = 1) {
    if (ll <= l && r <= rr)
        return mm[n];
    int m = (l + r) >> 1;
    if (ll > m) return QM(ll, rr, rs);
    if (rr <= m) return QM(ll, rr, ls);
    int ans = max(QM(ll, m, ls), QM(m + 1, rr, rs));
    if (num[m] && num[m] == num[m + 1])
        ans = max(ans, QR(ll, m, ls) + QL(m + 1, rr, rs));
    return ans;
}

int main() {
    int t, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &N, &m);
        B();
        while (m--) {
            scanf("%d%d%d", &V, &L, &R);
            ++L, ++R;
            if (V < 2)
                U();
            else if (V == 2)
                I();
            else if (V == 3)
                printf("%d\n", Q());
            else
                printf("%d\n", QM(L, R));

        }
    }
    return 0;
}