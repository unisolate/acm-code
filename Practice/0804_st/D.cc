#include <bits/stdc++.h>
#define MX 111111
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
int num[MX], mi[MX << 2], p[111], r[111];
char op[111];
using namespace std;
void pushUp(int n)
{
    mi[n] = min(mi[n << 1], mi[n << 1 | 1]);
}
void build(int l, int r, int n)
{
    if (l == r)
    {
        scanf("%d", &num[l]);
        mi[n] = num[l];
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushUp(n);
}
void update(int x, int v, int l, int r, int n)
{
    if (l == r)
    {
        num[l] = mi[n] = v;
        return;
    }
    int m = (l + r) >> 1;
    if (x <= m)
        update(x, v, lson);
    else update(x, v, rson);
    pushUp(n);
}
int query(int L, int R, int l, int r, int n)
{
    if (L <= l && r <= R)
        return mi[n];
    int ans = MX, m = (l + r) >> 1;
    if (L <= m)
        ans = min(ans, query(L, R, lson));
    if (m < R)
        ans = min(ans, query(L, R, rson));
    return ans;
}
int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    build(1, n, 1);
    while (q--)
    {
        scanf("%s", op);
        int k = 0, len = strlen(op);
        p[0] = 0;
        for (int i = 6; i < len; ++i)
            if (isdigit(op[i]))
                p[k] = p[k] * 10 + op[i] - '0';
            else p[++k] = 0;
        if (op[0] == 'q')
            printf("%d\n", query(p[0], p[1], 1, n, 1));
        else
        {
            for (int i = 0; i < k; ++i)
                r[i] = num[p[i]];
            for (int i = 0; i < k; ++i)
                update(p[i], r[(i + 1) % k], 1, n, 1);
        }
    }
    return 0;
}