#include <cstdio>
#include <algorithm>
#define MX 55555
#define INF 1111111
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define lc n<<1
#define rc n<<1|1
using namespace std;
int num[MX], mi[MX << 2], ma[MX << 2], N, L, R;
inline void up(int n)
{
    mi[n] = min(mi[lc], mi[rc]);
    ma[n] = max(ma[lc], ma[rc]);
}
void B(int l = 1, int r = N, int n = 1)
{
    if (l == r)
    {
        scanf("%d", &num[l]);
        mi[n] = ma[n] = num[l];
        return;
    }
    int m = l + r >> 1;
    B(lson), B(rson), up(n);
}
int Q1(int l = 1, int r = N, int n = 1)
{
    if (L <= l && r <= R)
        return ma[n];
    int ans = 0, m = l + r >> 1;
    if (L <= m)
        ans = max(ans, Q1(lson));
    if (m < R)
        ans = max(ans, Q1(rson));
    return ans;
}
int Q2(int l = 1, int r = N, int n = 1)
{
    if (L <= l && r <= R)
        return mi[n];
    int ans = INF, m = l + r >> 1;
    if (L <= m)
        ans = min(ans, Q2(lson));
    if (m < R)
        ans = min(ans, Q2(rson));
    return ans;
}
int main()
{
    int q;
    while (~scanf("%d%d", &N, &q))
    {
        B();
        while (q--)
            scanf("%d%d", &L, &R), printf("%d\n", Q1() - Q2());
    }
    return 0;
}