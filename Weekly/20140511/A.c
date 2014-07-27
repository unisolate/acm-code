#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 111
using namespace std;
int n, p[MAXN][MAXN], x[MAXN][MAXN];
int max(int a, int b)
{
    return a > b ? a : b;
}
int dp(int i, int j)
{
    if (p[i][j] >= 0)
        return p[i][j];
    if (i == n)
        return p[i][j] = x[i][j];
    return p[i][j] = x[i][j] + max(dp(i + 1, j), dp(i + 1, j + 1));
}
int main()
{
    memset(p, -1, sizeof(p));
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            cin >> x[i][j];
    cout << dp(1, 1) << endl;
    return 0;
}