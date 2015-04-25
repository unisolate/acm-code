#include <iostream>
using namespace std;
int x[11111], y[11111];
int main()
{
    int n, m = 1;
    y[1] = 1;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        bool flag = true;
        for (int j = 1; j <= m; ++j)
        {
            if (i % y[j])
            {
                x[i] = y[j];
                flag = false;
                continue;
            }
        }
        if (flag)
        {
            y[++m] = i;
        }
    }
    cout << m << endl;
    for (int i = 1; i < n; ++i)
        cout << x[i] << " ";
    cout << x[n] << endl;
    return 0;
}