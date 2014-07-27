/*
ID: unisola1
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
bool flag[10];
bool check(int n, int k)
{
    if (n >= 10 * k) 
        return true;
    while (k >= 1)
    {
        if (flag[n / k])
            return true;
        n %= k;
        k /= 10;
    }
    return false;
}
int main()
{
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
    int n, ans = 0, temp;
    cin >> n;
    for (int i = 0; i < 10; ++i)
        flag[i] = true;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        flag[temp] = false;
    }
    for (int i = 111; i < 1000; ++i)
    {
        if (check(i, 100))
            continue;
        for (int j = 11; j < 100; ++j)
        {
            if (check(j, 10))
                continue;
            if (check(i * (j / 10), 100))
                continue;
            if (check(i * (j % 10), 100))
                continue;
            if (check(i * j, 1000))
                continue;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}