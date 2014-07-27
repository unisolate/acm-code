#include <cstdio>
#define MAXN 100010
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1

using namespace std;

int sum[MAXN << 2], add[MAXN << 2], s[MAXN << 2], u[MAXN << 2], a[MAXN << 2];

void pushUp(int n)
{
    sum[n] = sum[n << 1] + sum[n << 1 | 1];
}

void build(int l, int r, int n)
{
    add[n] = 0;
    if (l == r)
    {
        scanf("%d%d%d", &s[n], &u[n], &a[n]);
        sum[n] = s[n];
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushUp(n);
}

void pushDown(int n, int m,int t)
{
    if (add[n])
    {
        add[n << 1] += add[n];
        add[n << 1 | 1] += add[n];
        sum[n << 1] += (t-add[n]) * (m - (m >> 1))*;
        sum[n << 1 | 1] += (t-add[n]) * (m >> 1)*;
        add[n] = 0;
    }
}

//update [L,R]
void update(int L, int R, int t, int l, int r, int n)
{
    if (L <= l && r <= R)
    {
        add[n] = t;
        sum[n] = 0;
        return;
    }
    pushDown(n, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m)
        update(L, R, v, lson);
    if (m < R)
        update(L, R, v, rson);
    pushUp(n);
}

int query(int L, int R, int l, int r, int n)
{
    if (L <= l && r <= R)
    {
        return sum[n];
    }
    pushDown(n, r - l + 1);
    int m = (l + r) >> 1;
    int ans = 0;
    if (L <= m)
        ans += query(L, R, lson);
    if (m < R)
        ans += query(L, R, rson);
    return ans;
}

int main()
{
    scanf("%d", &n);
    build(1, n, 1);
    scanf("%d", &m);
    int ans = 0;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &t, &L, &R);
        ans += query(L, R, 1, n, 1);
        update(L, R, t, 1, n, 1);
    }
    printf("%d\n", ans);
    return 0;
}