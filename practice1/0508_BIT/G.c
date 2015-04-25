#include <cstdio>
#include <cstring>
#define MAXN 100010
using namespace std;
int c[MAXN], start[MAXN], end[MAXN], head[MAXN], d;
bool vis[MAXN];
struct node
{
    int link, next;
} p[MAXN << 2];
void add(int x, int y)
{
    p[d].link = y;
    p[d].next = head[x];
    head[x] = d++;
}
void dfs(int u)
{
    start[u] = ++d;
    vis[u] = true;
    for (int i = head[u]; i != -1; i = p[i].next)
        if (!vis[p[i].link])
            dfs(p[i].link);
    end[u] = d;
}
void update(int n, int v)
{
    for (; n <= MAXN; n += (n & -n))
        c[n] += v;
}
int read(int n)
{
    int sum = 0;
    for (; n > 0; n -= (n & -n))
        sum += c[n];
    return sum;
}
int main()
{
    memset(head, -1, sizeof(head));
    int x, y, n, m;
    char op[2];
    scanf("%d", &n);
    d = 0;
    for (int i = 1; i < n; ++i)
    {
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    d = 0;
    dfs(1);
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; ++i)
        update(i, 1);
    scanf("%d", &m);
    while (m--)
    {
        scanf("%s%d", op, &x);
        if (op[0] == 'Q')
        {
            printf("%d\n", read(end[x]) - read(start[x] - 1));
        }
        else
        {
            if (vis[x])
                update(start[x], 1);
            else update(start[x], -1);
            vis[x] = (!vis[x]);
        }
    }
    return 0;
}