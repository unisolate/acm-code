#include <bits/stdc++.h>
using namespace std;
#define MX (int)1e5
#define INF (int)1e9
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define lc n<<1
#define rc n<<1|1
using namespace std;
int mi[MX << 2], N;
inline void up(int n)
{
    mi[n] = min(mi[lc], mi[rc]);
}
void B(int l = 1, int r = N, int n = 1)
{
    if (l == r)
    {
        scanf("%d", &mi[n]);
        return;
    }
    int m = l + r >> 1;
    B(lson), B(rson), up(n);
}
int Q(int L, int R, int l = 1, int r = N, int n = 1)
{
    if (L <= l && r <= R)
        return mi[n];
    int ans = INF, m = l + r >> 1;
    if (L <= m) ans = min(ans, Q(L, R, lson));
    if (m < R) ans = min(ans, Q(L, R, rson));
    return ans;
}
int main()
{
    int t, n, q, a, b, c, d;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        N = n * n, B();
        scanf("%d", &q);
        while (q--)
        {
            int ans = INF;
            scanf("%d%d%d%d", &a, &b, &c, &d);
            for (int i = a; i <= c; ++i)
                ans = min(ans, Q((i - 1) * n + b, (i - 1) * n + d));
            printf("%d\n", ans);
        }
    }
    return 0;
}