#include <bits/stdc++.h>
#define MX 55555
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define lc n<<1
#define rc n<<1|1
using namespace std;
int N, sum[MX], mm[MX << 2], lm[MX << 2], rm[MX << 2];
int get(int l, int r)
{
    return sum[r] - sum[l - 1];
}
void B(int l = 1, int r = N, int n = 1)
{
    if (l == r)
    {
        scanf("%d", &mm[n]);
        lm[n] = rm[n] = mm[n];
        sum[l] = sum[l - 1] + mm[n];
        return;
    }
    int m = l + r >> 1;
    B(lson), B(rson);
    lm[n] = max(lm[lc], get(l, m) + lm[rc]);
    rm[n] = max(rm[rc], get(m + 1, r) + rm[lc]);
    mm[n] = max(rm[lc] + lm[rc], max(mm[lc], mm[rc]));
}
int QL(int L, int R, int l = 1, int r = N, int n = 1)
{
    if (L <= l && r <= R)
        return lm[n];
    int m = l + r >> 1, ans;
    if (L > m) return QL(L, R, rson);
    if (R <= m) return QL(L, R, lson);
    return max(QL(m + 1, R, rson) + get(L, m), max(get(L, m), QL(L, m, lson)));
}
int QR(int L, int R, int l = 1, int r = N, int n = 1)
{
    if (L <= l && r <= R)
        return rm[n];
    int m = l + r >> 1, ans;
    if (L > m) return QR(L, R, rson);
    if (R <= m) return QR(L, R, lson);
    return max(QR(L, m, lson) + get(m + 1, R), max(get(m + 1, R), QR(m + 1, R, rson)));
}
int Q(int L, int R, int l = 1, int r = N, int n = 1)
{
    if (L <= l && r <= R)
        return mm[n];
    int m = l + r >> 1, ans;
    if (L > m) return Q(L, R, rson);
    if (R <= m) return Q(L, R, lson);
    return max(QR(L, m, lson) + QL(m + 1, R, rson), max(Q(L, m, lson), Q(m + 1, R, rson)));
}
int main()
{
    freopen("data.out", "r", stdin);
    freopen("A.out", "w", stdout);
    int m, L, R;
    scanf("%d", &N), B();
    scanf("%d", &m);
    while (m--)
        scanf("%d%d", &L, &R), printf("%d\n", Q(L, R));
    return 0;
}