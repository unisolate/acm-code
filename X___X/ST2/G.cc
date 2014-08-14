#include <cstdio>
#include <cmath>
#define MX 33333
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define lc n<<1
#define rc n<<1|1
using namespace std;
typedef long long ll;
ll sum[MX << 2], add[MX << 2], s, v;
int N;
inline void up(int n)
{
    sum[n] = sum[lc] + sum[rc];
}
void B(int l = 1, int r = N, int n = 1)
{
    add[n] = 0;
    if (l == r)
    {
        scanf("%lld", &sum[n]);
        s += sum[n];
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
void U(int L, int R, int l = 1, int r = N, int n = 1)
{
    if (L <= l && r <= R)
    {
        add[n] = v, sum[n] = v * (r - l + 1);
        return;
    }
    down(n, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) U(L, R, lson);
    if (m < R) U(L, R, rson);
    up(n);
}
ll Q(int L, int R, int l = 1, int r = N, int n = 1)
{
    if (L <= l && r <= R)
        return sum[n];
    down(n, r - l + 1);
    int m = l + r >> 1;
    ll ans = 0;
    if (L <= m) ans += Q(L, R, lson);
    if (m < R) ans += Q(L, R, rson);
    return ans;
}
int main()
{
    int m, l, r;
    while (~scanf("%d%d", &N, &m))
    {
        s = 0, B();
        while (m--)
        {
            scanf("%d%d", &l, &r);
            ll u = Q(l, r);
            if (Q(1, N) <= s)
                v = ceil((double)u / (r - l + 1));
            else v = floor((double)u / (r - l + 1));
            // v = u / (ll)(r - l + 1);
            // if (u % (ll)(r - l + 1) && Q(1, N) <= s) ++v;
            U(l, r);
        }
        for (int i = 1; i < N; ++i)
            printf("%lld ", Q(i, i));
        printf("%lld\n\n", Q(N, N));
    }
    return 0;
}