#include <bits/stdc++.h>
#define MX 55555
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define lc n<<1
#define rc n<<1|1
using namespace std;
int num, sum[MX << 2], mm[MX << 2], lm[MX << 2], rm[MX << 2];
int L, R, N;
inline void up(int n)
{
    sum[n] = sum[lc] + sum[rc];
    lm[n] = max(lm[lc], sum[lc] + lm[rc]);
    rm[n] = max(rm[rc], sum[rc] + rm[lc]);
    mm[n] = max(rm[lc] + lm[rc], max(mm[lc], mm[rc]));
}
void B(int l = 1, int r = N, int n = 1)
{
    if (l == r)
    {
        scanf("%d", &sum[n]);
        mm[n] = lm[n] = rm[n] = sum[n];
        return;
    }
    int m = l + r >> 1;
    B(lson), B(rson), up(n);
}
int QL(int l = 1, int r = N, int n = 1)
{
    if (L <= l && r <= R)
        return lm[n];
    int m = l + r >> 1, ans;
    if (L > m) return QL(rson);
    if (R <= m) return QL(lson);
    return max(QL(rson) + sum[lc], lm[lc]);
}
int QR(int l = 1, int r = N, int n = 1)
{
    if (L <= l && r <= R)
        return rm[n];
    int m = l + r >> 1, ans;
    if (L > m) return QR(rson);
    if (R <= m) return QR(lson);
    return max(QR(lson) + sum[rc], rm[rc]);
}
int Q(int l = 1, int r = N, int n = 1)
{
    if (L <= l && r <= R)
        return mm[n];
    int m = l + r >> 1, ans;
    if (L > m) return Q(rson);
    if (R <= m) return Q(lson);
    return max(QR(lson) + QL(rson), max(Q(lson), Q(rson)));
}
int main()
{
    int m;
    scanf("%d", &N), B();
    scanf("%d", &m);
    while (m--)
        scanf("%d%d", &L, &R), printf("%d\n", Q());
    return 0;
}