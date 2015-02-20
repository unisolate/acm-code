#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MX 100000000
using namespace std;
int cmp(int a, int b)
{
    return a < b;
}
int main()
{
    int n, t;
    double v;
    while (cin >> n && n)
    {
        int p[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> v >> t;
            if (t < 0)
                p[i] = MX;
            else
                p[i] = ceil(900 * 18 / v) + t;
        }
        sort(p, p + n, cmp);
        cout << p[0] << endl;
    }
    return 0;
}