#include <cstdio>
#include <algorithm>
#define MX 111111
#define lson l,m,n<<1
#define rson m,r,n<<1|1
using namespace std;
typedef long long ll;
int v, N, L, R, x[MX], y[MX], h[MX], p[MX], s[MX << 2];
void B(int l = 1, int r = N, int n = 1)
{
    if (l == r - 1) return;
    int m = (l + r) >> 1;
    B(lson), B(rson);
}
void U(int L, int R, int l = 1, int r = N, int n = 1)
{
    if (p[l] == L && p[r] == R)
    {
        if (s[n] < h[v]) s[n] = h[v];
        return;
    }
    int m = (l + r) >> 1;
    if (R <= p[m]) U(L, R, lson);
    else if (L >= p[m]) U(L, R, rson);
    else U(L, p[m], lson), U(p[m], R, rson);
}
ll Q(int l = 1, int r = N, int n = 1, int t = 0)
{
    if (s[n] < t) s[n] = t;
    if (l == r - 1) return (ll)(p[r] - p[l]) * s[n];
    int m = (l + r) >> 1;
    return Q(lson, s[n]) + Q(rson, s[n]);
}
int main()
{
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &x[i], &y[i], &h[i]);
        p[++N] = x[i], p[++N] = y[i];
    }
    sort(p + 1, p + N + 1);
    N = unique(p + 1, p + N + 1) - p - 1;
    B();
    for (v = 1; v <= m; ++v)
        U(x[v], y[v]);
    printf("%lld\n", Q());
    return 0;
}