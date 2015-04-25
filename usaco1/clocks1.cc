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
bool check(int *s)
{
    for (int i = 0; i < 9; ++i)
        if (s[i] != 12)
            return false;
    return true;
}
void run(int *s, int p)
{
    for (int i = 0; i < 9; ++i)
    {
        if (op[p][i])
        {
            int n = s[i] + 3;
            s[i] = n > 12 ? (n - 12) : n;
        }
    }
}
int main()
{
    freopen("clocks.in", "r", stdin);
    freopen("clocks.out", "w", stdout);
    int status[9];
    for (int i = 0; i < 9; ++i)
        cin >> status[i];
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            for (int k = 0; k < 9; ++k)
            {
                for (int l = 0; l < 9; ++l)
                {
                    int s[9];
                    for (int a = 0; a < 9; ++a)
                        s[a] = status[a];
                    run(s, i);
                    if (check(s))
                    {
                        cout << i + 1 << endl;
                        return 0;
                    }
                    run(s, j);
                    if (check(s))
                    {
                        cout << i + 1 << " " << j + 1 << endl;
                        return 0;
                    }
                    run(s, k);
                    if (check(s))
                    {
                        cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
                        return 0;
                    }
                    run(s, l);
                    if (check(s))
                    {
                        cout << i + 1 << " " << j + 1 << " " << k + 1 << " " << l + 1 << endl;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}