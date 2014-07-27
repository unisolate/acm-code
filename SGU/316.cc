/*
10.05.14 20:17	15 ms	58 kb
*/
#include <iostream>
using namespace std;
int main()
{
    int n, m, x, y;
    cin >> n >> m;
    int h[n + 1], s[n + 1];
    for (int i = 1; i <= n; ++i)
    {
        h[i] = 100;
        s[i] = 0;
    }
    while (m--)
    {
        cin >> x >> y;
        if (h[x] > 0)
        {
            if (h[y] > 0)
                s[x] += 3;
            h[y] -= 8;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (h[i] > 0)
            s[i] += h[i] / 2;
        cout << h[i] << " " << s[i] << endl;
    }
    return 0;
}