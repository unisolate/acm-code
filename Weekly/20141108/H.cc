#include <cstdio>
using namespace std;
int p[10001], q[10001];
int F(int x)
{
    return x == p[x] ? x : (p[x] = F(p[x]));
}
void init(int n)
{
    for (int i = 0; i < n; ++i)
    {
        p[i] = i;
        q[i] = 1;
    }
}
void U(int x, int y)
{
    x = F(x); y = F(y);
    if (x == y) return;
    q[y] += q[x];
    q[x] = 0;
    p[x] = y;
}
int main()
{
    int t, n, m, a, b, cas = 0;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        init(n);
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d", &a, &b);
            U(a - 1, b - 1);
        }
        printf("Case #%d:\n%d", ++cas, q[F(0)] - 1);
        for (int i = 1; i < n; ++i)
            printf(" %d", q[F(i)] - 1);
        putchar(10);
    }
    return 0;
}