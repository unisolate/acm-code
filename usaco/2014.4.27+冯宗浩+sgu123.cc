/*
27.04.14 18:06	15 ms	58 kb
求斐波那契数列之和 忘记n=1的情况撒比的WA了两次=_=
*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "1" << endl;
        return 0;
    }
    long long x = 1, y = 2, ans = 2;
    for (int i = 2; i < n; ++i)
    {
        y += x;
        x = y - x;
        ans += x;
    }
    cout << ans << endl;
    return 0;
}
