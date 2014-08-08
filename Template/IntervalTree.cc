/*
Interval Tree ( Segment Tree )
Unommented & Compressed Version
By Uni, 2014/8/8
*/
#include <bits/stdc++.h>
#define MX (int)1e6
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define lc n<<1
#define rc n<<1|1
using namespace std;
int num[MX], sum[MX << 2], max[MX << 2], add[MX << 2];
int L, R, x, v;
inline void up(int n)
{
    sum[n] = sum[lc] + sum[rc];
    max[n] = max(max[lc], max[rc]);
}
void B(int l = 1, int r = n, int n = 1)
{
    // add[n] = 0;
    if (l == r)
    {
        scanf("%d", &num[l]);
        sum[n] = max[n] = num[l];
        return;
    }
    int m = l + r >> 1;
    B(lson), B(rson), up(n);
}
// Prepare: x, v
void U(int l = 1, int r = n, int n = 1)
{
    if (l == r)
    {
        // sum[n] = min[n] = v;
        return;
    }
    int m = l + r >> 1;
    if (x <= m) U(x, v, lson);
    else U(x, v, rson);
    up(n);
}
// Prepare: L, R
int Q(int l = 1, int r = n, int n = 1)
{
    if (L <= l && r <= R)
    {
        // return sum[n];
        // return max[n];
    }
    down(n, r - l + 1);
    int ans = 0, m = l + r >> 1;
    if (L <= m) ans += Q(L, R, lson);
    // ans = max(ans, Q(L, R, lson));
    if (m < R) ans += Q(L, R, rson);
    // ans = max(ans, Q(L, R, rson));
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
void U(int l = 1, int r = n, int n = 1)
{
    if (L <= l && r <= R)
    {
        add[n] += v, sum[n] += v * (r - l + 1);
        return;
    }
    down(n, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) U(L, R, v, lson);
    if (m < R) U(L, R, v, rson);
    up(n);
}