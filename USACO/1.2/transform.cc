/*
ID: unisola1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char before[10][10], after[10][10], mirror[10][10];
int main()
{
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> before[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> after[i][j];
        }
    }
    bool flag = true;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (after[i][j] != before[n - j - 1][i])
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
    {
        cout << 1 << endl;
        return 0;
    }
    flag = true;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (after[i][j] != before[n - i - 1][n - j - 1])
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
    {
        cout << 2 << endl;
        return 0;
    }
    flag = true;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (after[i][j] != before[j][n - i - 1])
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
    {
        cout << 3 << endl;
        return 0;
    }
    flag = true;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            mirror[i][j] = before[i][n - j - 1];
            if (after[i][j] != before[i][n - j - 1])
            {
                flag = false;
            }
        }
    }
    if (flag)
    {
        cout << 4 << endl;
        return 0;
    }
    bool flag1 = true, flag2 = true, flag3 = true;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (after[i][j] != mirror[n - j - 1][i])
            {
                flag1 = false;
            }
            if (after[i][j] != mirror[n - i - 1][n - j - 1])
            {
                flag2 = false;
            }
            if (after[i][j] != mirror[j][n - i - 1])
            {
                flag3 = false;
            }
        }
    }
    if (flag1 || flag2 || flag3)
    {
        cout << 5 << endl;
        return 0;
    }
    flag = true;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (after[i][j] != before[i][j])
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
    {
        cout << 6 << endl;
        return 0;
    }
    cout << 7 << endl;
    return 0;
}