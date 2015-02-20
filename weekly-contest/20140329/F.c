#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool p[101][101];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(p, false, sizeof(p));
        int n, m, kk, x, y, ans = 0;
        cin >> n >> m >> kk;
        for (int i = 0; i < m; ++i)
        {
            cin >> x >> y;
            p[x][y] = true;
            p[y][x] = true;
        }
        bool flag = true;
        while (flag)
        {
            flag = false;
            for (int i = 0; i < n; ++i)
            {
                if (flag)
                    break;
                for (int j = i + 1; j < n; ++j)
                {
                    if (flag)
                        break;
                    if (p[i][j])
                        continue;
                    int cnt = 0;
                    for (int k = 0; k < n; ++k)
                    {
                        if (p[i][k] && p[j][k])
                            cnt++;
                    }
                    if (cnt >= kk)
                    {
                        flag = true;
                        ans ++;
                        p[i][j] = true;
                        p[j][i] = true;
                        continue;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}