#include <stdio.h>
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
#define MAXN 100010
int pos, num[MAXN], t[MAXN << 2], lm[MAXN << 2], rm[MAXN << 2], ln[MAXN << 2], rn[MAXN << 2];
int max(int a, int b)
{
    return a > b ? a : b;
}
void pushup(int n, int s)
{
    ln[n] = ln[n << 1];
    rn[n] = rn[n << 1 | 1];
    t[n] = max(t[n << 1], t[n << 1 | 1]);
    lm[n] = lm[n << 1];
    if(lm[n] == (s - (s >> 1)) && rn[n << 1] == ln[n << 1 | 1])
        lm[n] += lm[n << 1 | 1];
    rm[n] = rm[n << 1 | 1];
    if(rm[n] == (s >> 1) && rn[n << 1] == ln[n << 1 | 1])
        rm[n] += rm[n << 1];
    if(rn[n << 1] == ln[n << 1 | 1])
        t[n] = max(t[n], rm[n << 1] + lm[n << 1 | 1]);
}
void build(int l, int r, int n)
{
    if(l == r)
    {
        scanf("%d", &num[pos]);
        ln[n] = rn[n] = num[pos];
        pos++;
        t[n] = lm[n] = rm[n] = 1;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(n, r - l + 1);
}
int query(int L, int R, int l, int r, int n)
{
    if(L <= l && r <= R)
        return t[n];
    int ans = 0, m = (l + r) >> 1;
    if(L <= m)
        ans = max(ans, query(L, R, lson));
    if(m < R)
        ans = max(ans, query(L, R, rson));
    if(L <= m && m < R && rn[n << 1] == ln[n << 1 | 1])
        ans = max(ans, (rm[n << 1] > (m - L + 1)) ? (m - L + 1) : rm[n << 1] + (lm[n << 1 | 1] > (R - m)) ? (R - m) : lm[n << 1 | 1]);
    return ans;
}
int main()
{
    int n, q, i, a, b;
    while(~scanf("%d%d", &n, &q) && n)
    {
        pos = 1;
        build(1, n, 1);
        for(i = 0; i < q; ++i)
        {
            scanf("%d%d", &a, &b);
            printf("%d\n", query(a, b, 1, n, 1));
        }
    }
    return 0;
}
