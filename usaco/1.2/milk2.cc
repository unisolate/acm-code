/*
ID: unisola1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int flag[1000001];
int main()
{
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    int n, x, y, s = 1000001, m = 0, a = 0, b = 0, c = 1, d = 0;
    cin >> n;
    memset(flag, 0, sizeof(flag));
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y;
        for (int j = x; j < y; ++j)
        {
            flag[j] = 1;
        }
        if (s > x)
        {
            s = x;
        }
        if (m < y)
        {
            m = y;
        }
    }
    for (int i = s; i <= m; ++i)
    {
        // cout << flag[i] << " ";
        if (flag[i] == flag[i - 1])
        {
            if (flag[i])
                c++; else
                d++;
        }
        else if (flag[i] != flag[i - 1])
        {
            if (flag[i - 1] && a < c)
            {
                a = c;
            }
            if (flag[i] && b < d)
            {
                b = d;
            }
            c = 1;
            d = 1;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}