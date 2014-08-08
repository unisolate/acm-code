#include <bits/stdc++.h>
#define MX (int)1e6
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
using namespace std;

int num[MX], sum[MX << 2], max[MX << 2], add[MX << 2];
int L, R, x, v;

//Push the info to upper level
inline void pushUp(int n)
{
    sum[n] = sum[n << 1] + sum[n << 1 | 1];
    max[n] = max(max[n << 1], max[n << 1 | 1]);
}

// Build interval tree
void build(int l = 1, int r = n, int n = 1)
{
    add[n] = 0; // Use it in interval update
    if (l == r)
    {
        scanf("%d", &num[l]);
        sum[n] = max[n] = num[l]; // Notice the order
        return;
    }
    int m = l + r >> 1;
    build(lson), build(rson), pushUp(n);
}

// Update position x
// Prepare: x, v
void update(int l = 1, int r = n, int n = 1)
{
    if (l == r)
    {
        sum[n] = min[n] = v; // Addition is also acceptable
        return;
    }
    int m = l + r >> 1;
    if (x <= m) update(x, v, lson);
    else update(x, v, rson);
    pushUp(n);
}

// Query interval [L,R]
// Prepare: L, R
int query(int l = 1, int r = n, int n = 1)
{
    if (L <= l && r <= R)
    {
        return sum[n];
        // return max[n];
    }
    pushDown(n, r - l + 1);
    int ans = 0, m = l + r >> 1;
    if (L <= m) ans += query(L, R, lson);
    // ans = max(ans, query(L, R, lson));
    if (m < R) ans += query(L, R, rson);
    // ans = max(ans, query(L, R, rson));
    return ans;
}

/*
Interval update part
*/

// Push lazy lag to lower level
void pushDown(int n, int m)
{
    if (add[n])
    {
        add[n << 1] += add[n];
        add[n << 1 | 1] += add[n];
        sum[n << 1] += add[n] * (m - (m >> 1));
        sum[n << 1 | 1] += add[n] * (m >> 1);
        add[n] = 0;
    }
}

// Update [L,R]
// Prepare: L, R, v
void update(int l = 1, int r = n, int n = 1)
{
    if (L <= l && r <= R)
    {
        add[n] += v, sum[n] += v * (r - l + 1);
        return;
    }
    pushDown(n, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, v, lson);
    if (m < R) update(L, R, v, rson);
    pushUp(n);
}