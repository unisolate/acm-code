/*
ID: unisola1
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
bool check(int base, int num)
{
    int n[15], k = 0;
    while (num >= base)
    {
        n[k] = num % base;
        num /= base;
        ++k;
    }
    n[k] = num;
    bool flag = true;
    for (int i = 0; i <= k; ++i)
    {
        if (n[i] != n[k - i])
        {
            flag = false;
            break;
        }
    }
    if (k == 0)
        flag = true;
    return flag;
}
int main()
{
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
    int n, s, cnt, num;
    cin >> n >> s;
    cnt = 0;
    num = s + 1;
    while (cnt < n)
    {
        int flag = 0;
        for (int i = 2; i <= 10; ++i)
        {
            if (check(i, num))
            {
                flag++;
            }
        }
        if (flag >= 2)
        {
            cnt++;
            cout << num << endl;
        }
        num++;
    }
    return 0;
}