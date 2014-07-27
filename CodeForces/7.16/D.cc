#include <bits/stdc++.h>
using namespace std;
int p[6][6], f[3][6], m[256], ans;
void check()
{
    int k;
    for (int i = 1; i < 6; ++i)
        if (f[1][i])
        {
            k = 0;
            for (int j = 1; j < 6; ++j)
                if (p[i][j] && !f[2][j])++k;
            if (k > 1)return;
        }
    for (int i = 1; i < 6; ++i)
        if (f[2][i])
        {
            k = 0;
            for (int j = 1; j < 6; ++j)
                if (p[j][i] && !f[1][j])++k;
            if (k > 1)return;
        }
    k = 0;
    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 6; ++j)
            if (!f[1][i] && !f[2][j] && p[i][j])
                ++k;
    if (k > 1)return;
    k = 0;
    for (int i = 1; i < 3; ++i)
        for (int j = 1; j < 6; ++j)
            if (f[i][j])++k;
    if (k < ans)ans = k;
}
void Try(int i, int j)
{
    if (j > 5)
        ++i, j = 1;
    if (i > 2)
    {
        check();
        return;
    }
    Try(i, j + 1);
    f[i][j] = 1;
    Try(i, j + 1);
    f[i][j] = 0;
}
int main()
{
    memset(p, 0, sizeof(p));
    memset(f, 0, sizeof(f));
    m['R'] = 1; m['G'] = 2; m['B'] = 3; m['Y'] = 4; m['W'] = 5;
    int n; char c[5];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", c);
        ++p[m[c[0]]][c[1] - '0'];
    }
    ans = 10;
    Try(1, 1);
    printf("%d\n", ans);
    return 0;
}