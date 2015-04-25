/*
05.05.14 17:01	15 ms	2830 kb
*/
#include <iostream>
#include <string>
#define INF 11111
using namespace std;
int f, v, a[111][111], p[111][111];
short n[111][111][111];
int max(int a, int b)
{
    return a > b ? a : b;
}
int dp(int x, int y)
{
    if (p[x][y] < INF)
        return p[x][y];
    int mx = -INF;
    if (x == f)
    {
        for (int i = y; i <= v; ++i)
        {
            if (a[f][i] > mx)
            {
                n[x][y][f] = i;
                //cout << n[x][y][f] << endl;
            }
            mx = max(mx, a[f][i]);
        }
        return p[x][y] = mx;
    }
    for (int i = y; i <= v - f + x; ++i)
    {
        if (dp(x + 1, i + 1) + a[x][i] > mx)
        {
            n[x][y][x] = i;
            for (int j = x + 1; j <= f; ++j)
                n[x][y][j] = n[x + 1][i + 1][j];
            //cout << n[x][y] << endl;
        }
        mx = max(mx, dp(x + 1, i + 1) + a[x][i]);
    }
    return p[x][y] = mx;
}
int main()
{
    cin >> f >> v;
    for (int i = 1; i <= f; ++i)
        for (int j = 1; j <= v; ++j)
        {
            cin >> a[i][j];
            p[i][j] = INF;
        }
    cout << dp(1, 1) << endl;
    for (int i = 1; i <= f; ++i)
        cout << n[1][1][i] << " ";
    cout << endl;
    // cout << n[1][1] << endl;
    return 0;
}