#include <bits/stdc++.h>
#define MX 5555
using namespace std;
char s[MX];
int f[MX][MX], damn[MX][MX];
int shit(int l, int r)
{
    if (damn[l][r] != -1)
        return damn[l][r];
    int m = l + r >> 1;
    bool flag = true;
    if ((l + r) % 2)
    {
        for (int i = 0; m - i >= l; ++i)
        {
            if (flag)
            {
                if (s[m - i] == s[m + 1 + i])
                    damn[m - i][m + 1 + i] = 1;
                else
                {
                    damn[m - i][m + 1 + i] = 0;
                    flag = false;
                }
            }
            else damn[m - i][m + 1 + i] = 0;
        }
    }
    else
    {
        for (int i = 0; m - 1 - i >= l; ++i)
        {
            if (flag)
            {
                if (s[m - 1 - i] == s[m + 1 + i])
                    damn[m - 1 - i][m + 1 + i] = 1;
                else
                {
                    damn[m - 1 - i][m + 1 + i] = 0;
                    flag = false;
                }
            }
            else damn[m - 1 - i][m + 1 + i] = 0;;
        }
    }
    return damn[l][r];
}
int fuck(int l, int r)
{
    // printf("#%d %d\n", l, r);
    if (l >= r)
        return 0;
    // if (l == r)
    //     return 1;
    if (f[l][r] != -1)
        return f[l][r];
    f[l][r] = 0;
    if (shit(l, r) == 1)
        f[l][r] = (l + r >> 1) + 1;
    else f[l][r] = fuck(l + 1, r - 1);
    return f[l][r] = f[l][r] + fuck(l, r - 1) + fuck(l + 1, r);
}
int main()
{
    int q, l, r;
    memset(damn, -1, sizeof(damn));
    memset(f, -1, sizeof(f));
    scanf("%s%d", s, &q);
    while (q--)
    {
        scanf("%d%d", &l, &r);
        printf("%d\n", fuck(l - 1, r - 1) + r - l + 1);
    }
    return 0;
}