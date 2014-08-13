#include <cstdio>
#define MX 111111
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define lc n<<1
#define rc n<<1|1
using namespace std;
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
        sum[n] = 1;
        return;
    }
    int m = l + r >> 1;
    B(lson), B(rson), up(n);
}
void down(int n, int m)
{
    if (add[n])
    {
        add[lc] = add[rc] = add[n];
        sum[lc] = add[n] * (m - (m >> 1));
        sum[rc] = add[n] * (m >> 1);
        add[n] = 0;
    }
}
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
int Q(int l = 1, int r = N, int n = 1)
{
    if (L <= l && r <= R)
        return sum[n];
    down(n, r - l + 1);
    int ans = 0, m = l + r >> 1;
    if (L <= m) ans += Q(lson);
    if (m < R) ans += Q(rson);
    return ans;
}
int main()
{
    int t, q, cas = 0;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &N), B();
        scanf("%d", &q);
        while (q--)
            scanf("%d%d%d", &L, &R, &v), U();
        L = 1, R = N;
        printf("Case %d: The total value of the hook is %d.\n", ++cas, Q());
    }
    return 0;
}