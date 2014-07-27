#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
using namespace std;
int f[1111];
struct p
{
    int co, pos;
    bool flag[1111];
} c[1111];
int cmp(struct p a, struct p b)
{
    return a.co < b.co;
}
int main()
{
    int n, m, x, y;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &f[i]);
        c[i].pos = i;
        c[i].co = 0;
        memset(c[i].flag, false, sizeof(c[i].flag));
    }
    while (m--)
    {
        scanf("%d%d", &x, &y);
        c[x].co += f[y];
        c[x].flag[y] = true;
        c[y].co += f[x];
        c[y].flag[x] = true;
    }
    sort(c + 1, c + 1 + n, cmp);
    int sum = 0;
    bool ha[1111];
    for (int i = 1; i <= n; ++i)
    {
        sum += c[i].co;
        ha[c[i].pos]=true;
        for (int j = 1; j <= n; ++j)
            if (c[j].flag[c[i].pos]&&ha[c[i].pos])
            {
                c[j].co -= f[c[i].pos];
                c[j].flag[c[i].pos] = false;
            }
        sort(c + i + 1, c + 1 + n, cmp);
    }
    printf("%d\n", sum);
    return 0;
}