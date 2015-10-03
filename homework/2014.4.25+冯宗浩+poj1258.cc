/*
Info : 396K	47MS	C++	1029B	2014-04-26 00:57:01
单纯的最小生成树问题。参考的白书上的算法。图论知识基础一点没有，需要恶补。
前几次用G++提交都是诡异的MLE。改用C++提交后变成了RE，于是各种调整数组大小最后无奈全部开成MAXN*MAXN终于AC之……
*/
#include <iostream>
#include <algorithm>
#define MAXN 11111
using namespace std;
int w[MAXN], p[MAXN], r[MAXN], u[MAXN], v[MAXN];
int cmp(int i, int j)
{
    return w[i] < w[j];
}
int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}
void kruskal(int n, int m)
{
    int ans = 0;
    for (int i = 0; i <= n; ++i)
        p[i] = i;
    for (int i = 0; i <= m; ++i)
        r[i] = i;
    sort(r, r + m, cmp);
    for (int i = 0; i < m; ++i)
    {
        int e = r[i], x = find(u[e]), y = find(v[e]);
        if (x != y)
        {
            ans += w[e];
            p[x] = y;
        }
    }
    cout << ans << endl;
}
int main()
{
    int n;
    while (cin >> n && n)
    {
        int m = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cin >> w[m];
                u[m] = i;
                v[m] = j;
                ++m;
            }
        }
        kruskal(n, m);
    }
    return 0;
}