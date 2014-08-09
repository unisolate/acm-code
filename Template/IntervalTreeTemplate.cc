/*
Interval Tree ( Segment Tree )
Commented & Compressed Version
By Uni, 2014/8/8
*/

#include <bits/stdc++.h>
#define MX (int)1e6
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define lc n<<1
#define rc n<<1|1
using namespace std;

int num[MX], sum[MX << 2], ma[MX << 2], add[MX << 2];
int L, R, N, x, v;

//Push the info to upper level
inline void up(int n)
{
    sum[n] = sum[lc] + sum[rc];
    ma[n] = max(ma[lc], ma[rc]);
    mi[n] = min(mi[lc], mi[rc]);
}

// Build interval tree
void B(int l = 1, int r = N, int n = 1)
{
    add[n] = 0; // Use it in interval update
    if (l == r)
    {
        scanf("%d", &num[l]);
        sum[n] = ma[n] = mi[n] = num[l]; // Notice the order
        return;
    }
    int m = l + r >> 1;
    B(lson), B(rson), up(n);
}

// Update position x
// Prepare: x, v
void U(int l = 1, int r = N, int n = 1)
{
    if (l == r)
    {
        sum[n] = mi[n] = v; // Addition is also acceptable
        return;
    }
    int m = l + r >> 1;
    if (x <= m) U(lson);
    else U(rson);
    up(n);
}

// Query interval [L,R]
// Prepare: L, R
int Q(int l = 1, int r = N, int n = 1)
{
    if (L <= l && r <= R)
    {
        return sum[n];
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

/*
Interval update part
*/

// Push lazy lag to lower level
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

// Update [L,R]
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