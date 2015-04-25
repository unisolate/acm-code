#include <cstdio>
#include <algorithm>
#define maxn 510
#define it tree[p1][p2]
using namespace std;
struct Seg_Tree2D
{
    int minv, maxv;
    friend Seg_Tree2D operator + (const Seg_Tree2D &a, const Seg_Tree2D &b)
    {
        Seg_Tree2D c;
        c.minv = min(a.minv, b.minv);
        c.maxv = max(a.maxv, b.maxv);
        return c;
    }
} tree[maxn << 2][maxn << 2];
int matrix[maxn][maxn], n, m;
void Build2(int p1, int p2, int l, int r, int a, int b)
{
    if (a == b)
    {
        if (l == r)
            it.minv = it.maxv = matrix[l][a];
        else
            it = tree[p1 << 1][p2] + tree[p1 << 1 | 1][p2];
    }
    else
    {
        int mid = (a + b) >> 1;
        Build2(p1, p2 << 1, l, r, a, mid), Build2(p1, p2 << 1 | 1, l, r, mid + 1, b);
        it = tree[p1][p2 << 1] + tree[p1][p2 << 1 | 1];
    }
}
void Build1(int p1, int l, int r)
{
    if (l == r)
    {
        Build2(p1, 1, l, r, 1, m);
        return ;
    }
    int mid = (l + r) >> 1;
    Build1(p1 << 1, l, mid), Build1(p1 << 1 | 1, mid + 1, r);
    Build2(p1, 1, l, r, 1, m);
}
void Modify2(int p1, int p2, int l, int r, int a, int b, int y, int v)
{
    if (a == b)
    {
        if (l == r)
            it.minv = it.maxv = v;
        else
            it = tree[p1 << 1][p2] + tree[p1 << 1 | 1][p2];
    }
    else
    {
        int mid = (a + b) >> 1;
        if (y <= mid)
            Modify2(p1, p2 << 1, l, r, a, mid, y, v);
        else
            Modify2(p1, p2 << 1 | 1, l, r, mid + 1, b, y, v);
        it = tree[p1][p2 << 1] + tree[p1][p2 << 1 | 1];
    }
}
void Modify1(int p1, int l, int r, int x, int y, int v)
{
    if (l == r)
    {
        Modify2(p1, 1, l, r, 1, m, y, v);
        return ;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        Modify1(p1 << 1, l, mid, x, y, v);
    else
        Modify1(p1 << 1 | 1, mid + 1, r, x, y, v);
    Modify2(p1, 1, l, r, 1, m, y, v);
}
Seg_Tree2D Query2(int p1, int p2, int l, int r, int a, int b)
{
    if (l == a && r == b)
        return it;
    int mid = (l + r) >> 1;
    if (b <= mid)
        return Query2(p1, p2 << 1, l, mid, a, b);
    else if (mid < a)
        return Query2(p1, p2 << 1 | 1, mid + 1, r, a, b);
    return Query2(p1, p2 << 1, l, mid, a, mid) + Query2(p1, p2 << 1 | 1, mid + 1, r, mid + 1, b);
}
Seg_Tree2D Query1(int p1, int l, int r, int ax, int ay, int bx, int by)
{
    if (l == ax && r == bx)
        return Query2(p1, 1, 1, m, ay, by);
    int mid = (l + r) >> 1;
    if (bx <= mid)
        return Query1(p1 << 1, l, mid, ax, ay, bx, by);
    else if (mid < ax)
        return Query1(p1 << 1 | 1, mid + 1, r, ax, ay, bx, by);
    return Query1(p1 << 1, l, mid, ax, ay, mid, by) + Query1(p1 << 1 | 1, mid + 1, r, mid + 1, ay, bx, by);
}
void read()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &matrix[i][j]);
    Build1(1, 1, n);
}
void Query()
{
    char task[10];
    int q;
    scanf("%d", &q);
    Seg_Tree2D ans;
    for (int i = 1, a, b, c, d; i <= q; i++)
    {
        scanf("%s", task);
        if (task[0] == 'c')
        {
            scanf("%d %d %d", &a, &b, &c);
            Modify1(1, 1, n, a, b, c);
        }
        else
        {
            scanf("%d %d %d %d", &a, &b, &c, &d);
            ans = Query1(1, 1, n, a, b, c, d);
            printf("%d %d\n", ans.maxv, ans.minv);
        }
    }
}
int main()
{
    read();
    Query();
    return 0;
}