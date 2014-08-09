#include <bits/stdc++.h>
#define MX 222222
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define lc n<<1
#define rc n<<1|1
using namespace std;
struct num
{
    int v, id, pos;
} a[MX];
bool c1(num a, num b)
{
    return a.v < b.v;
}
bool c2(num a, num b)
{
    return a.pos < b.pos;
}
int min[MX << 2], max[MX << 2], L, R;
inline void up(int n)
{
    max[n] = max(max[lc], max[rc]);
}
void B(int l = 1, int r = n, int n = 1)
{
    if (l == r)
    {
        scanf("%d", &num[l]);
        sum[n] = max[n] = num[l];
        return;
    }
    int m = l + r >> 1;
    B(lson), B(rson), up(n);
}
// Prepare: L, R
int Q(int l = 1, int r = n, int n = 1)
{
    if (L <= l && r <= R)
    {
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
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i].v), a[i].pos = i;
        sort(a + 1, a + n + 1, c1);
        for (int i = 1; i <= n; ++i)
            a[i].id = i;
        sort(a + 1, a + n + 1, c2);
        B();
        scanf("%d", &q);
        while (q--)
        {
            scanf("%d%d", &L, &R);
            printf("%d", Q());
        }
    }
    return 0;
}