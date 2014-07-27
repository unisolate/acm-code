/*
ID: unisola1
PROG: clocks
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int op[9][9] = {{1, 1, 0, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 1, 0, 0},
    {0, 1, 0, 1, 1, 1, 0, 1, 0},
    {0, 0, 1, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 0, 1, 1}
};
int status[100000][9];
char ans[100000][10];
bool flag[100000];
bool search(int k, int l)
{
    if (!flag[k])
    {
        for (int i = 0; i < 9; ++i)
        {
            run(k + i, status[k], i);
            if (check(status[k + i]))
            {
                return true;
            }
        }
        return false;
    }
    flag = true;
    for (int i = 0; i < 9; ++i)
    {
    	search(k,++l);
    }
}
void run(int k, int *s, int p)
{
    for (int i = 0; i < 9; ++i)
    {
        if (op[p][i])
        {
            int n = s[i] + 3;
            status[k][i] = n > 12 ? (n - 12) : n;
        }
    }
}
bool check(int *s)
{
    for (int i = 0; i < 9; ++i)
        if (s[i] != 12)
            return false;
    return true;
}
int main()
{
    freopen("clocks.in", "r", stdin);
    freopen("clocks.out", "w", stdout);
    init();
    for (int i = 0; i < 9; ++i)
        cin >> status[0][i];
    search(0, 0);
    return 0;
}