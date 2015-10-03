/*
Interval Tree ( Segment Tree )
Unommented & Compressed Version
By Uni, 2014/8/8
*/
#include <cstdio>
#include <algorithm>
#define MX 1111111
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define lc n<<1
#define rc n<<1|1
using namespace std;
int sum[MX << 2], cl[MX << 2];
int L, R, N, v;
inline void up(int n)
{
    sum[n] = sum[lc] | sum[rc];
}
void B(int l = 1, int r = N, int n = 1)
{
    cl[n] = 0, sum[n] = 2;
    if (l == r)
    {
        return;
    }
    int m = (l + r) >> 1;
    B(lson), B(rson);
}
void down(int n, int m)
{
    if (cl[n])
    {
        cl[lc] = cl[rc] = cl[n];
        sum[lc] = sum[rc] = cl[n];
        cl[n] = 0;
    }
}
// Prepare: L, R
int Q(int l = 1, int r = N, int n = 1)
{
    if (L <= l && r <= R)
    {
        return sum[n];
    }
    down(n, r - l + 1);
    int ans = 0, m = (l + r) >> 1;
    if (L <= m) ans = ans | Q(lson);
    // ans = max(ans, Q(lson));
    if (m < R) ans = ans | Q(rson);
    // ans = max(ans, Q(rson));
    return ans;
}
// Prepare: L, R, v
void U(int l = 1, int r = N, int n = 1)
{
    if (L <= l && r <= R)
    {
        cl[n] = 1 << (v - 1);
        sum[n] = 1 << (v - 1);
        return;
    }
    down(n, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) U(lson);
    if (m < R) U(rson);
    up(n);
}
int main()
{
    int m, q[99];
    char op[9];
    while (scanf("%d%d", &N, &m) && N + m)
    {
        B();
        while (m--)
        {
            scanf("%s", op);
            if (op[0] == 'P')
            {
                scanf("%d%d%d", &L, &R, &v);
                if (L > R)swap(L, R);
                U();
            }
            else
            {
                scanf("%d%d", &L, &R);
                if (L > R)swap(L, R);
                int x = Q(), y = 0, cnt = 1;
                while (x)
                {
                    if (x % 2)
                    {
                        // printf("#%d %d\n", x, cnt);
                        q[y++] = cnt;
                    }
                    ++cnt;
                    x >>= 1;
                }
                if (y > 0)
                {
                    for (int i = 0; i < y - 1; ++i)
                        printf("%d ", q[i]);
                    printf("%d\n", q[y - 1]);
                }
                else printf("\n");
            }
        }
    }
    return 0;
}