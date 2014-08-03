#include <bits/stdc++.h>
#define MX 222
using namespace std;
char p[MX][MX];
int wtf[MX][MX][2];
int n, m;
int fuck(int pos, int i, int right)
{
    if (i == n)
        return 0;
    if (wtf[pos][i][right] != -1)
        return wtf[pos][i][right];
    int ans = 0, t = pos, add = 0;
    for (int j = 0; j < m; ++j)
    {
        int k = pos + (right ? j : -j);
        // printf("#%d\n", k);
        if (k >= m) k -= m;
        else if (k < 0) k += m;
        if (p[i][k] == 'W')
            t = k;
    }
    // printf("##%d\n", t);
    if (right)
    {
        if (t >= pos)
            add = t - pos;
        else add = (m - pos - 1) * 2 + pos - t, right = 0;
    }
    else
    {
        if (t >= 0)
            add = pos;
        else add = pos * 2 + t - pos, right = 1;
    }
    // printf("###%d\n", add);
    pos = t;
    ans += add;
    // right = !right;
    int hehe = (int)1e9;
    if (right)
    {
        for (int j = pos; j < m; ++j)
        {
            if (j != m - 1)
                hehe = min(hehe, min(j - pos + fuck(j, i + 1, 0), m - 1 - pos + m - 1 - j + fuck(j, i + 1, 1)));
            else hehe = min(hehe, j - pos + fuck(j, i + 1, 0));
        }
    }
    else
    {
        for (int j = pos; j >= 0; --j)
        {
            if (j != 0)
                hehe = min(hehe, min(pos - j + fuck(j, i + 1, 1), pos + j + fuck(j, i + 1, 0)));
            else hehe = min(hehe, pos - j + fuck(j, i + 1, 1));
        }
    }
    return wtf[pos][i][right] = ans + hehe/* + fuck(pos, i + 1, right)*/;
}
int main()
{
    memset(wtf, -1, sizeof(wtf));
    scanf("%d%d", &n, &m);
    getchar();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            scanf("%c", &p[i][j]);
        getchar();
    }
    printf("%d\n", fuck(0, 0, 1) + n - 1);
    return 0;
}