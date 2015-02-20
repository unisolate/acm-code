#include <cstdio>
#include <queue>
using namespace std;
int a[9], b[9], aa, bb;
bool vis[1000000];
int g(int *ar)
{
    int ret = 0, j = 1;
    for (int i = 6; i > 0; --i)
    {
        ret += j * ar[i];
        j *= 10;
    }
    return ret;
}
int c(int num, int op)
{
    int ret = 0;
    if (op == 0)
    {
        ret += (num % 10) * 1, num /= 10;
        ret += (num % 10) * 10, num /= 10;
        ret += (num % 10) * 100000, num /= 10;
        ret += (num % 10) * 10000, num /= 10;
        ret += (num % 10) * 100, num /= 10;
        ret += (num % 10) * 1000, num /= 10;
    }
    else if (op == 1)
    {
        ret += (num % 10) * 1, num /= 10;
        ret += (num % 10) * 10, num /= 10;
        ret += (num % 10) * 10000, num /= 10;
        ret += (num % 10) * 100000, num /= 10;
        ret += (num % 10) * 1000, num /= 10;
        ret += (num % 10) * 100, num /= 10;
    }
    else if (op == 2)
    {
        ret += (num % 10) * 100000, num /= 10;
        ret += (num % 10) * 10000, num /= 10;
        ret += (num % 10) * 100, num /= 10;
        ret += (num % 10) * 1000, num /= 10;
        ret += (num % 10) * 1, num /= 10;
        ret += (num % 10) * 10, num /= 10;
    }
    else if (op == 3)
    {
        ret += (num % 10) * 10000, num /= 10;
        ret += (num % 10) * 100000, num /= 10;
        ret += (num % 10) * 100, num /= 10;
        ret += (num % 10) * 1000, num /= 10;
        ret += (num % 10) * 10, num /= 10;
        ret += (num % 10) * 1, num /= 10;
    }
    return ret;
}
int bfs()
{
    queue<int> q;
    q.push(aa);
    int l = 0, x = 1, y = 0;
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        if (tmp == bb)
            return l;
        vis[tmp] = true;
        for (int i = 0; i < 4; ++i)
        {
            int z = c(tmp, i);
            if (!vis[z])
                q.push(z), ++y;
        }
        --x;
        if (!x)
            ++l, x = y, y = 0;
    }
    return -1;
}
int main()
{
    while (~scanf("%d", &a[1]))
    {
        memset(vis, false, sizeof(vis));
        for (int i = 2; i < 7; ++i)
            scanf("%d", &a[i]);
        for (int i = 1; i < 7; ++i)
            scanf("%d", &b[i]);
        aa = g(a), bb = g(b);
        printf("%d\n", bfs());
    }
    return 0;
}