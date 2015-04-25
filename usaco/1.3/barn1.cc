/*
ID: unisola1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
struct gap
{
    int g, k;
} gg[200];
int cmp(struct gap a, struct gap b)
{
    return a.g > b.g;
}
int cmp1(int a, int b)
{
    return a < b;
}
int main()
{
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
    int m, s, c, num[200];
    bool flag[200];
    memset(flag, false, sizeof(flag));
    cin >> m >> s >> c;
    flag[c - 1] = true;
    for (int i = 0; i < c; ++i)
    {
        cin >> num[i];
    }
    sort(num, num + c, cmp1);
    for (int i = 0; i < c - 1; ++i)
    {
        gg[i].g = num[i + 1] - num[i];
        gg[i].k = i;
    }
    sort(gg, gg + c, cmp);
    for (int i = 0; i < m - 1; ++i)
    {
        flag[gg[i].k] = true;
    }
    int sum = 0, l = 0;
    for (int i = 0; i < c; ++i)
    {
        if (flag[i])
        {
            sum += num[i] - num[l] + 1;
            l = i + 1;
        }
    }
    cout << sum << endl;
    return 0;
}