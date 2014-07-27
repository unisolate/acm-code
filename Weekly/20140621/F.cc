#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 111
using namespace std;
int r, c, d;
int x[MAXN *MAXN], y[MAXN *MAXN], p[MAXN *MAXN];
char u;
char q[MAXN][MAXN];
bool visit[MAXN][MAXN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int dx2[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy2[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int search(int x, int y)
{
    if (visit[x][y])
        return 0;
    visit[x][y] = true;
    int res = 1;
    for (int k = 0; k < 4; ++k)
    {
        int xx = x + dx[k];
        int yy = y + dy[k];
        if (xx < 0 || yy < 0 || xx >= r || yy >= c)
            continue;
        if (q[xx][yy] == u)
            continue;
        if (visit[xx][yy])
            continue;
        res += search(xx, yy);
    }
    return res;
}
bool dfs(int x, int y)
{
    if (visit[x][y])
        return false;
    visit[x][y] = true;
    if (x == 0 || y == 0 || x == r - 1 || y == c - 1)
        return true;
    for (int k = 0; k < 8; ++k)
    {
        int xx = x + dx2[k];
        int yy = y + dy2[k];
        if (xx < 0 || yy < 0 || xx >= r || yy >= c)
            continue;
        if (visit[xx][yy])
            continue;
        if (q[xx][yy] == '#')
            continue;
        if (dfs(xx, yy))
            return true;
    }
    return false;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &r, &c, &d);
        memset(p, 0, sizeof(p));
        bool flag = true;
        int sum = 0;
        for (int i = 0; i < d; ++i)
        {
            scanf("%d%d%d", &x[i], &y[i], &p[i]);
            if (p[i] <= 0)
                flag = false;
            sum += p[i];
        }
        for (int i = 0; i < r; ++i)
        {
            scanf("%s", q[i]);
        }
        int shade = 0;
        if (flag)
        {
            for (int i = 0; i < r; ++i)
                for (int j = 0; j < c; ++j)
                    if (q[i][j] == '.')
                    {
                        ++shade;
                    }
            if (sum != shade)
                flag = false;
        }
        if (flag)
        {
            u = '#';
            memset(visit, false, sizeof(visit));
            for (int i = 0; i < d; ++i)
            {
                if (search(x[i], y[i]) != p[i])
                {
                    // printf("##1 %d %d\n", x[i], y[i]);
                    flag = false;
                    break;
                }

            }
        }
        if (flag)
        {
            u = '.';
            memset(visit, false, sizeof(visit));
            bool flg = true;
            for (int i = 0; i < r; ++i)
            {
                for (int j = 0; j < c; ++j)
                {
                    if (q[i][j] == '#')
                    {
                        flg = false;
                        if (search(i, j) != (r * c - shade))
                        {
                            // printf("##2 %d %d\n", i, j);
                            flag = false;
                        }
                        break;
                    }
                }
                if (!flg)
                    break;
            }
            if (flg && shade != r * c)
                flag = false;
        }
        if (flag)
        {
            for (int i = 0; i < r - 1; ++i)
            {
                for (int j = 0; j < c - 1; ++j)
                {
                    if (q[i][j] == '#' && q[i][j + 1] == '#' && q[i + 1][j] == '#' && q[i + 1][j + 1] == '#')
                    {
                        // printf("##3 %d %d\n", i, j);
                        flag = false;
                        break;
                    }
                }
                if (!flag)
                    break;
            }
        }
        if (flag)
        {
            bool flg = true;
            for (int i = 0; i < min(2, r); ++i)
            {
                if (!flg)
                    break;
                for (int j = 0; j < min(2, c); ++j)
                    if (q[i][j] == '.')
                    {
                        flg = false;
                        break;
                    }
            }
            if (flg)
                flag = false;

        }
        if (flag)
        {
            for (int i = 0; i < d; ++i)
            {
                memset(visit, false, sizeof(visit));
                if (!visit[x[i]][y[i]] && !dfs(x[i], y[i]))
                {
                    // printf("##4 %d %d\n", x[i], y[i]);
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
            puts("solved");
        else puts("not solved");
    }
    return 0;
}