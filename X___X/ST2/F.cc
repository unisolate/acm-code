#include <cstdio>
#include <algorithm>
#define MX 333
#define lson1 l,m,n<<1
#define rson1 m+1,r,n<<1|1
#define lc1 n<<1
#define rc1 n<<1|1
#define lson2 a,m,o<<1
#define rson2 m+1,b,o<<1|1
#define lc2 o<<1
#define rc2 o<<1|1
using namespace std;
int mi[MX << 2][MX << 2], N;
void B2(int l, int r, int n, int a = 1, int b = N, int o = 1)
{
    if (a == b)
    {
        if (l == r)
            scanf("%d", &mi[n][o]);
        else mi[n][o] = min(mi[lc1][o], mi[rc1][o]);
    }
    else
    {
        int m = a + b >> 1;
        B2(l, r, n, lson2), B2(l, r, n, rson2);
        mi[n][o] = min(mi[n][lc2], mi[n][rc2]);
    }
}
void B1(int l = 1, int r = N, int n = 1)
{
    if (l == r)
    {
        B2(l, r, n);
        return;
    }
    int m = l + r >> 1;
    B1(lson1), B1(rson1);
    B2(l, r, n);
}
int Q2(int l, int r, int n, int a, int b, int o)
{
    if (l == a && r == b)
        return mi[n][o];
    int m = l + r >> 1;
    if (b <= m)
        return Q2(l, m, n, a, b, lc2);
    if (m < a)
        return Q2(m + 1, r, n, a, b, rc2);
    return min(Q2(l, m, n, lson2), Q2(m + 1, r, n, rson2));
}
int Q1(int x1, int y1, int x2, int y2, int l = 1, int r = N, int n = 1)
{
    if (l == x1 && r == x2)
        return Q2(1, N, n, y1, y2, 1);
    int m = l + r >> 1;
    if (x2 <= m)
        return Q1(x1, y1, x2, y2, lson1);
    if (m < x1)
        return Q1(x1, y1, x2, y2, rson1);
    return min(Q1(x1, y1, m, y2, lson1), Q1(m + 1, y1, x2, y2, rson1));
}
int main()
{
    int t, q, x1, x2, y1, y2;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &N), B1();
        scanf("%d", &q);
        while (q--)
        {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            printf("%d\n", Q1(x1, y1, x2, y2));
        }
    }
    return 0;
}
