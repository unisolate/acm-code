#include <bits/stdc++.h>
#define MX 111111
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define lc n<<1
#define rc n<<1|1
using namespace std;
typedef long long ll;
ll sum[MX << 2];
int L, R, N, x;
inline void up(int n)
{
    sum[n] = sum[lc] + sum[rc];
}
void B(int l = 1, int r = N, int n = 1)
{
    if (l == r)
    {
        scanf("%lld", &sum[n]);
        return;
    }
    int m = l + r >> 1;
    B(lson), B(rson), up(n);
}
void U(int l = 1, int r = N, int n = 1)
{
    if (r - l + 1 == sum[n])
        return;
    if (l == r)
    {
        sum[n] = sqrt(sum[n]);
        return;
    }
    int m = l + r >> 1;
    if (L <= m) U(lson);
    if (m < R) U(rson);
    up(n);
}
ll Q(int l = 1, int r = N, int n = 1)
{
    if (L <= l && r <= R)
        return sum[n];
    ll ans = 0, m = l + r >> 1;
    if (L <= m) ans += Q(lson);
    if (m < R) ans += Q(rson);
    return ans;
}
int main()
{
    int m, p, cas = 0;
    while (~scanf("%d", &N))
    {
        printf("Case #%d:\n", ++cas);
        B();
        scanf("%d", &m);
        while (m--)
        {
            scanf("%d%d%d", &p, &L, &R);
            if (L > R) swap(L, R);
            if (p) printf("%lld\n", Q());
            else U();
        }
        putchar(10);
    }
    return 0;
}