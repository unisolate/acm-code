/*
28.04.14 15:52	15 ms	66 kb
求2001年m月第n天是星期几.
*/
#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int t[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m <= 12 && n <= t[m - 1])
    {
        int d = n - 1;
        for (int i = 1; i < m; ++i)
            d += t[i - 1];
        cout << (d % 7) + 1 << endl;
    }
    else cout << "Impossible" << endl;
    return 0;
}