/*
01.05.14 13:53	15 ms	98 kb
一堆方块放在一起，求表面积。
*/
#include <iostream>
using namespace std;
int main()
{
    int n, m, ans = 0;
    char a;
    cin >> n >> m;
    int t[n + 2][m + 2];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a;
            t[i][j] = a - '0';
        }
    }
    for (int i = 0; i <= n + 1; ++i)
    {
        t[i][0] = 0;
        t[i][m + 1] = 0;
    }
    for (int i = 0; i <= m + 1; ++i)
    {
        t[0][i] = 0;
        t[n + 1][i] = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            int v = t[i][j];
            ans += (t[i - 1][j] < v) ? (v - t[i - 1][j]) : 0;
            ans += (t[i + 1][j] < v) ? (v - t[i + 1][j]) : 0;
            ans += (t[i][j - 1] < v) ? (v - t[i][j - 1]) : 0;
            ans += (t[i][j + 1] < v) ? (v - t[i][j + 1]) : 0;
            if (v)
                ans += 2;
        }
    }
    cout << ans << endl;
    return 0;
}