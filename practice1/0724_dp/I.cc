#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define MX 111
using namespace std;
int x, y, dp[MX][MX], path[MX][MX];
string m[MX], n[MX];
void lcs()
{
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= x; ++i)
        for (int j = 1; j <= y; ++j)
        {
            if (m[i] == n[j])
                dp[i][j] = dp[i - 1][j - 1] + 1, path[i][j] = 1;
            else if (dp[i - 1][j] >= dp[i][j - 1])
                dp[i][j] = dp[i - 1][j], path[i][j] = 2;
            else
                dp[i][j] = dp[i][j - 1], path[i][j] = 3;
        }
}
void printPath(int i, int j)
{
    if (i == 0 || j == 0) return;
    if (path[i][j] == 1)
    {
        printPath(i - 1, j - 1);
        cout << m[i] << ' ';
    }
    else if (path[i][j] == 2) printPath(i - 1, j);
    else printPath(i, j - 1);
}
int main()
{
    while (cin >> m[1] && m[1] != "#")
    {
        x = 2, y = 1;
        while (cin >> m[x] && m[x] != "#")
            ++x;
        --x;
        while (cin >> n[y] && n[y] != "#")
            ++y;
        --y;
        lcs();
        printPath(x, y);
        putchar(10);
    }
    return 0;
}