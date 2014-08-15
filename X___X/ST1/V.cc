#include <cstdio>
#include <algorithm>
#define MX 222222
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define lc n<<1
#define rc n<<1|1
using namespace std;
int ma[MX << 2], L, R, N;
inline void up(int n)
{
    ma[n] = max(ma[lc], ma[rc]);
}
void B(int l = 1, int r = N, int n = 1)
{
    if (l == r)
    {
        scanf("%d", &ma[n]);
        return;
    }
    int m = l + r >> 1;
    B(lson), B(rson), up(n);
}
void U(int l = 1, int r = N, int n = 1)
{
    if (l == r)
    {
        ma[n] = R;
        return;
    }
    int m = l + r >> 1;
    if (L <= m) U(lson);
    else U(rson);
    up(n);
}
int Q(int l = 1, int r = N, int n = 1)
{
    if (L <= l && r <= R)
        return ma[n];
    int ans = 0, m = l + r >> 1;
    if (L <= m) ans = max(ans, Q(lson));
    if (m < R) ans = max(ans, Q(rson));
    return ans;
}
int main()
{
    int m;
    char p[9];
    while (~scanf("%d%d", &N, &m))
    {
        B();
        while (m--)
        {
            scanf("%s%d%d", p, &L, &R);
            if (p[0] == 'Q') printf("%d\n", Q());
            else U();
        }
    }
    return 0;
}