#include <cstdio>
#include <cstring>
#include <algorithm>
#define MX 55555
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define lc n<<1
#define rc n<<1|1
using namespace std;
struct P
{
    int l, r, v;
} p[500050];
int cmp(P a, P b)
{
    return a.v < b.v;
}
int sum[MX << 2], add[MX << 2];
int L, R, N, v;
inline void up(int n)
{
    sum[n] = sum[lc] + sum[rc];
}
void B(int l = 1, int r = N, int n = 1)
{
    add[n] = 0;
    if (l == r)
    {
        sum[n] = 0;
        return;
    }
    int m = l + r >> 1;
    B(lson), B(rson), up(n);
}
void down(int n, int m)
{
    if (add[n])
    {
        add[lc] = add[n];
        add[rc] = add[n];
        sum[lc] = add[n] * (m - (m >> 1));
        sum[rc] = add[n] * (m >> 1);
        add[n] = 0;
    }
}
// Prepare: L, R, v
void U(int l = 1, int r = N, int n = 1)
{
    if (L <= l && r <= R)
    {
        add[n] = v, sum[n] = v * (r - l + 1);
        return;
    }
    down(n, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) U(lson);
    if (m < R) U(rson);
    up(n);
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
int main()
{
    int m;
    while (~scanf("%d%d", &N, &m))
    {
        B();
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%d", &p[i].l, &p[i].r, &p[i].v);
            ++p[i].l;
        }
        sort(p, p + m, cmp);
        for (int i = 0; i < m; ++i)
        {
            L = p[i].l, R = p[i].r, v = p[i].v;
            U();
        }
        L = 1, R = N;
        printf("%d\n", Q());
    }
    return 0;
}