#include <bits/stdc++.h>
#define MX 111
using namespace std;
struct operate
{
    int x, y, o;
} op[MX *MX];
struct l
{
    int x, y, t;
} leave[MX *MX];
char s[MX][MX];
int x[9] = {0, 1, 1, -1, -1, 0, 1, 0, -1};
int y[9] = {0, 1, -1, 1, -1, 1, 0, -1, 0};
int cmp(l a, l b)
{
    return a.t < b.t;
}
int main()
{
    int T, n, m, f, k;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d%d", &n, &m, &f, &k);
        for (int i = 1; i <= n; ++i)
            scanf("%s", s[i] + 1);
        for (int i = 0; i < k; ++i)
            scanf("%d%d%d", &leave[i].t, &leave[i].x, &leave[i].y);
        sort(leave, leave + k, cmp);
        int lp = 0;
        for (int t = 1; t <= f; ++t)
        {
            int pos = 0;
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= m; ++j)
                {
                    int awake = 0;
                    for (int k = 1; k <= 8; ++k)
                    {
                        int p = i + x[k], q = j + y[k];
                        if (p > 0 && p <= n && q > 0 && q <= m && s[p][q] == '1') ++awake;
                    }
                    if (s[i][j] == '1' && (awake < 2 || awake > 3))
                        op[++pos].x = i, op[pos].y = j, op[pos].o = 1;
                    else if (s[i][j] == '0' && awake == 3)
                        op[++pos].x = i, op[pos].y = j, op[pos].o = 2;
                }
            for (int i = 1; i <= pos; ++i)
            {
                if (op[i].o == 1)
                    s[op[i].x][op[i].y] = '0';
                else if (op[i].o == 2)
                    s[op[i].x][op[i].y] = '1';
            }
            while (lp < k && leave[lp].t == t)
                s[leave[lp].x][leave[lp].y] = 'X', ++lp;
        }
        for (int i = 1; i <= n; ++i)
            printf("%s\n", s[i] + 1);
    }
    return 0;
}