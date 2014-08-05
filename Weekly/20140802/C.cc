#include <bits/stdc++.h>
#define MX 222
using namespace std;
int n, m;
char p[MX][MX];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%s", p[i]);
    for (int i = n - 1; i >= 0; --i)
    {
        bool flag = true;
        for (int j = 0; j < m; ++j)
            if (p[i][j] == 'W')
            {
                flag = false;
                break;
            }
        if (flag)
            --n;
        else break;
    }
    int ans = 0, pos = 0;
    bool right = true;
    for (int i = 0; i < n; ++i)
    {
        int l = pos, r = pos;
        for (int j = 0; j < pos; ++j)
            if (p[i][j] == 'W')
            {
                l = j;
                break;
            }
        for (int j = m - 1; j > pos; --j)
            if (p[i][j] == 'W')
            {
                r = j;
                break;
            }
        if (right)
        {
            if (l != pos)
                ans += 2 * (m - 1 - pos) + pos - l, pos = l, right = !right;
            else ans += r - pos, pos = r;
        }
        else
        {
            if (r != pos)
                ans += 2 * pos + r - pos, pos = r, right = !right;
            else ans += pos - l, pos = l;
        }
        if (i == n - 1)
            break;
        int t = pos;
        if (right)
        {
            for (int j = m - 1; j >= pos; --j)
                if (p[i + 1][j] == 'W')
                {
                    t = j;
                    break;
                }
            ans += t - pos;
        }
        else
        {
            for (int j = 0; j <= pos; ++j)
                if (p[i + 1][j] == 'W')
                {
                    t = j;
                    break;
                }
            ans += pos - t;
        }
        pos = t;
        right = !right;
    }
    printf("%d\n", ((ans + n - 1) >= 0 ? ans + n - 1 : 0));
    return 0;
}