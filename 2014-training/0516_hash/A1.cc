#include <cstdio>
#include <cstring>
using namespace std;
const int MS = 1505, MX = 15, MOD = MS * MS;
char s[MS * 2][MX], c[MS *MS][MX * 2];
int pos, head[MS *MS], next[MS *MS];
int get(int u)
{
    int ha = 0;
    for (int i = 0; c[u][i]; ++i)
        ha = (ha * 27 + c[u][i] - 'a') % 100000;
    return ha;
}
void insert()
{
    int h = get(pos), u = head[h];
    while (u != -1)
    {
        if (strcmp(c[u], c[pos]) == 0)
            return;
        u = next[u];
    }
    next[pos] = head[h];
    head[h] = pos;
    pos++;
}
int main()
{
    int t, m, n;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas)
    {
        memset(head, -1, sizeof(head));
        scanf("%d%d", &m, &n);
        getchar();
        for (int i = 0; i < m + n; ++i)
            gets(s[i]);
        pos = 0;
        for (int i = 0; i < m; ++i)
            for (int j = m; j < m + n; ++j)
            {
                strcpy(c[pos], s[i]);
                strcat(c[pos], s[j]);
                insert();
            }
        printf("Case %d: %d\n", cas, pos);
    }
    return 0;
}