#include <bits/stdc++.h>
#define MX 111111
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define lc n<<1
#define rc n<<1|1
using namespace std;
int sum[MX << 2];
int L, R, N;
char ans[MX];
inline void up(int n)
{
    sum[n] = sum[lc] * sum[rc];
}
void B(int l = 1, int r = N, int n = 1)
{
    if (l == r)
    {
        scanf("%d", &sum[n]);
        if (sum[n] > 0) sum[n] = 1;
        else if (sum[n] < 0) sum[n] = -1;
        else sum[n] = 0;
        return;
    }
    int m = l + r >> 1;
    B(lson), B(rson), up(n);
}
void U(int l = 1, int r = N, int n = 1)
{
    if (l == r)
    {
        sum[n] = R;
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
    {
        return sum[n];
    }
    int ans = 1, m = l + r >> 1;
    if (L <= m) ans *= Q(lson);
    if (m < R) ans *= Q(rson);
    return ans;
}
int main()
{
    int k;
    char op[9];
    while (~scanf("%d%d", &N, &k))
    {
        B();
        int z = 0;
        for (int i = 0; i < k; ++i)
        {
            scanf("%s%d%d", op, &L, &R);
            if (op[0] == 'C')
            {
                if (R > 0) R = 1;
                else if (R < 0) R = -1;
                else R = 0;
                U();
            }
            else
            {
                int q = Q();
                if (q == 0)ans[z++] = '0';
                else if (q > 0)ans[z++] = '+';
                else ans[z++] = '-';
            }
        }
        ans[z] = '\0';
        printf("%s\n", ans);
    }
    return 0;
}
/*
4 6
-2 6 0 -1
C 1 10
P 1 4
C 3 7
P 2 2
C 4 -5
P 1 4
5 9
1 5 -2 4 3
P 1 2
P 1 5
C 4 -5
P 1 5
P 4 5
C 3 0
P 1 5
C 4 -5
C 4 -5
*/