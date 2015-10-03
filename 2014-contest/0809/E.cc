#include <bits/stdc++.h>
#define MX 111111
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define lc n<<1
#define rc n<<1|1
using namespace std;
int num[MX], sum[MX << 2], add[MX << 2];
int L, R, N, x, v;
inline void up(int n)
{
    sum[n] = sum[lc] + sum[rc];
}
void B(int l = 1, int r = N, int n = 1)
{
    add[n] = 0;
    if (l == r)
    {
        scanf("%d", &num[l]);
        sum[n] = num[l];
        return;
    }
    int m = l + r >> 1;
    B(lson), B(rson), up(n);
}
void down(int n, int m)
{
    if (add[n])
    {
        add[lc] += add[n];
        add[rc] += add[n];
        sum[lc] += add[n] * (m - (m >> 1));
        sum[rc] += add[n] * (m >> 1);
        add[n] = 0;
    }
}
// Prepare: L, R
int Q(int l = 1, int r = N, int n = 1)
{
    if (L <= l && r <= R)
    {
        return sum[n];
    }
    down(n, r - l + 1);
    int ans = 0, m = l + r >> 1;
    if (L <= m) ans += Q(lson);
    if (m < R) ans += Q(rson);
    return ans;
}
// Prepare: L, R, v
void U(int l = 1, int r = N, int n = 1)
{
    if (L <= l && r <= R)
    {
        add[n] += v, sum[n] += v * (r - l + 1);
        return;
    }
    down(n, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) U(lson);
    if (m < R) U(rson);
    up(n);
}
int main()
{
    int m, t;
    scanf("%d", &N);
    B();
    scanf("%d", &m);
    while (m--)
    {
        scanf("%d", &t);
        if (t == 1)
        {
            scanf("%d%d", &L, &R);
            printf("%I64d\n", Q());
        }
        else
        {
            scanf("%d%d%d", &L, &R, &v);
            U();
        }
    }
    return 0;
}