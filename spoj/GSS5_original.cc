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
    int m, t, x1, x2, y1, y2;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &N), B();
        scanf("%d", &m);
        while (m--)
        {
            int ans = -INF;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if (y1 < x2) ans = QL(x2, y2) + QR(x1, y1) + get(y1 + 1, x2 - 1);
            else if (y1 >= y2) ans = max(Q(x2, y2), QL(x2, y2) + QR(x1, x2 - 1));
            else ans = max(Q(x2, y1),
                               max(QR(x1, x2 - 1) + QL(x2, y1),
                                   max(QR(x2, y1) + QL(y1 + 1, y2),
                                       QR(x1, x2 - 1) + QL(y1 + 1, y2) + get(x2, y1))));
            printf("%d\n", ans);
        }
    }
    return 0;
}