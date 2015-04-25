/*
15.05.14 21:05	31 ms	58 kb
*/
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int ans[n];
    memset(ans, 0, sizeof(ans));
    while (m--)
    {
        int a, b, x, y;
        cin >> a >> b;
        for (int i = 0; i < n; ++i)
        {
            cin >> x >> y;
            if ((a > b && x > y) || (a == b && x == y) || (a < b && x < y))
                ans[i] += 2;
            if ((a - b) == (x - y))
                ans[i] += 3;
            if (a == x)
                ans[i] += 1;
            if (b == y)
                ans[i] += 1;
        }
    }
    for (int i = 0; i < n - 1; ++i)
        cout << ans[i] << " ";
    cout << ans[n - 1] << endl;
    return 0;
}