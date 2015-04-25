/*
ID: unisola1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
bool check(int y)
{
    if (y % 100 == 0 && y % 400 != 0)
        return false;
    if (y % 4 == 0)
        return true;
    return false;
}
int main()
{
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
    int n, k = 0, ans[7], year = 1900,
           day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    memset(ans, 0, sizeof(ans));
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 12; ++j)
        {
            ans[k]++;
            k += day[j];
            if (j == 1 && check(year))
                k++;
            k %= 7;
        }
        year++;
    }
    for (int i = 0; i < 6; ++i)
    {
        cout << ans[i] << " ";
    }
    cout << ans[6] << endl;
    return 0;
}