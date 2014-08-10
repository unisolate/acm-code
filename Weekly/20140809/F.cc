#include <bits/stdc++.h>
#define MX 111111
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define lc n<<1
#define rc n<<1|1
using namespace std;
/*int num[MX], sum[MX << 2];
int L, R, N, x, v;
inline void up(int n)
{
    sum[n] = sum[lc] + sum[rc];
}
void B(int l = 1, int r = n, int n = 1)
{
    // add[n] = 0;
    if (l == r)
    {
        scanf("%d", &num[l]);
        sum[n] = ma[n] = num[l];
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
        // return sum[n];
        // return ma[n];
    }
    down(n, r - l + 1);
    int ans = 0, m = l + r >> 1;
    if (L <= m) ans += Q(lson);
    // ans = max(ans, Q(lson));
    if (m < R) ans += Q(rson);
    // ans = max(ans, Q(rson));
    return ans;
}
void down(int n, int m)
{
    if (add[n])
    {
        add[lc] += add[n];
        add[rc] += add[n];
        sum[lc] += add[n] * (m - (m >> 1));
        sum[rc] += add[n] * (m >> 1);
        add[n] = 0;
    }
}
// Prepare: L, R, v
void U(int l = 1, int r = n, int n = 1)
{
    if (L <= l && r <= R)
    {
        add[n] += v, sum[n] += v * (r - l + 1);
        return;
    }
    down(n, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) U(lson);
    if (m < R) U(rson);
    up(n);
}*/
int num[1111];
int main()
{
    int n, x, s1 = 0, s2 = 0;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &num[i]);
    }
    for (x = 1; x <= 100; ++x)
    {
        for (int i = 0; i < n; ++i)
        {
            // scanf("%d", &num[i]);
            // printf("%d\n", num[i]^x);
            s1 += num[i], s2 += (num[i] ^ x);
        }
        // printf("%d %d\n", s1, s2);
        // for (int i = 0; i < n; ++i)
        //     s1 = s1 ^ x, printf("%d ", s1);
        for (int i = 1; i <= 1000; ++i)
            if ((s1 ^ i) == s2)
            {
                printf("%d %d %d\n", x, i, (s1 ^ (x))^(s1^n));
                // for (int j = 1; j <= 1000; ++j)
                //     for (int k = 1; k <= 1000; ++k)
                //         if ((k ^ j) == i)
                //         {
                //             printf("##%d %d\n", j, k);
                //             break;
                //         }
            }
        // printf("\n%d\n", s1 ^ (x * n));
    }
    return 0;
}
/*
5 5
1 2 3 4 5 6 7 8 9 10
*/