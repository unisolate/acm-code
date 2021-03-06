#include <cstdio>
#include <cstring>
#include <algorithm>
#define MX (int)1e6
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define lc n<<1
#define rc n<<1|1
using namespace std;
int num[MX], sum[MX << 2], ma[MX << 2], mi[MX << 2], add[MX << 2];
int L, R, N, x, v;
inline void up(int n)
{
    sum[n] = sum[lc] + sum[rc];
    ma[n] = max(ma[lc], ma[rc]);
    mi[n] = min(mi[lc], mi[rc]);
}
void B(int l = 1, int r = N, int n = 1)
{
    // add[n] = 0;
    if (l == r)
    {
        scanf("%d", &num[l]);
        sum[n] = ma[n] = num[l];
        return;
    }
    int m = l + r >> 1;
    B(lson), B(rson), up(n);
}
// Prepare: x, v
void U(int l = 1, int r = N, int n = 1)
{
    if (l == r)
    {
        // sum[n] = mi[n] = v;
        return;
    }
    int m = l + r >> 1;
    if (x <= m) U(lson);
    else U(rson);
    up(n);
}
// Prepare: L, R
int Q(int l = 1, int r = N, int n = 1)
{
    if (L <= l && r <= R)
    {
        // return sum[n];
        // return ma[n];
    }
    down(n, r - l + 1);
    int ans = 0, m = l + r >> 1;
    if (L <= m) ans += Q(lson);
    // ans = max(ans, Q(lson));
    if (m < R) ans += Q(rson);
    // ans = max(ans, Q(rson));
    return ans;
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
    int n;
    while (~scanf("%d", &n))
    {
        while (n--)
            scanf("%d%d%s", &L, &R, op);
    }
    return 0;
}