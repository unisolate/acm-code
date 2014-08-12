#include <bits/stdc++.h>
#define MX 11111
#define INF (int)1e9
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define lc n<<1
#define rc n<<1|1
using namespace std;
int N, sum[MX << 2], mm[MX << 2], lm[MX << 2], rm[MX << 2];
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
int QL(int L, int R, int l = 1, int r = N, int n = 1)
{
    printf("QL %d %d %d %d %d\n",L,R,l,r,n);
    if (L > R) return 0;
    if (L <= l && r <= R)
        return lm[n];
    int m = l + r >> 1, ans;
    if (L > m) return QL(L, R, rson);
    if (R <= m) return QL(L, R, lson);
    printf("=====\n####%d %d %d\n", QL(L, R, rson) + sum[lc], sum[lc], QL(L, R, lson));
    return max(QL(L, R, rson) + sum[lc], max(sum[lc], QL(L, R, lson)));
}
int QR(int L, int R, int l = 1, int r = N, int n = 1)
{
    if (L > R) return 0;
    if (L <= l && r <= R)
        return rm[n];
    int m = l + r >> 1, ans;
    if (L > m) return QR(L, R, rson);
    if (R <= m) return QR(L, R, lson);
    return max(QR(L, R, lson) + sum[rc], rm[rc]);
}
int Q(int L, int R, int l = 1, int r = N, int n = 1)
{
    if (L > R) return 0;
    if (L <= l && r <= R)
        return mm[n];
    int m = l + r >> 1, ans;
    if (L > m) return Q(L, R, rson);
    if (R <= m) return Q(L, R, lson);
    return max(QR(L, R, lson) + QL(L, R, rson), max(Q(L, R, lson), Q(L, R, rson)));
}
int QS(int L, int R, int l = 1, int r = N, int n = 1)
{
    if (L > R) return 0;
    if (L <= l && r <= R)
        return sum[n];
    int ans = 0, m = l + r >> 1;
    if (L <= m) ans += QS(L, R, lson);
    if (m < R) ans += QS(L, R, rson);
    return ans;
}
int main()
{
    int m, t, x1, x2, y1, y2;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &N), B();
        for (int i = 1; i <= 13; ++i)
            printf("#%d %d %d %d %d\n", i,sum[i], lm[i], rm[i], mm[i]);
        scanf("%d", &m);
        while (m--)
        {
            int ans = -INF;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if (y1 < x2)
            {
                ans = QL(x2, y2) + QR(x1, y1) + QS(y1 + 1, x2 - 1);
                printf("#%d %d %d\n", QL(x2, y2), QR(x1, y1), QS(y1 + 1, x2 - 1));
            }
            else if (y1 >= y2) ans = max(Q(x2, y2), QL(x2, y2) + QR(x1, x2 - 1));
            else ans = max(Q(x2, y1),
                               max(QR(x1, x2 - 1) + QL(x2, y1),
                                   max(QR(x2, y1) + QL(y1 + 1, y2),
                                       QR(x1, x2 - 1) + QL(y1 + 1, y2) + QS(x2, y1))));
            printf("%d\n", ans);
        }
    }
    return 0;
}