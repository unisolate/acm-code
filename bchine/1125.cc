#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int cmp(int a, int b)
{
    return a > b;
}
int cmp1(int a, int b)
{
    return a < b;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int t[n][n], f[n][n], sum[n], num[n];
        bool flag[n][n], h[n * n + 1];
        memset(flag, false, sizeof(flag));
        memset(h, false, sizeof(h));
        for (int i = 0; i < n; ++i)
        {
            sum[i] = 0;
            for (int j = 0; j < n; ++j)
            {
                cin >> t[i][j];
                h[t[i][j]] = true;
                if (t[i][j] == -1)
                    flag[i][j] = true;
                else sum[i] += t[i][j];
            }
        }
        int k = 0;
        for (int i = 1; i < n * n + 1; ++i)
        {
            if (!h[i])
                num[k++] = i;
        }
        sort(num, num + n, cmp);
        sort(sum, sum + n, cmp1);
        int s = num[0] + sum[0];
        bool x = true;
        for (int i = 1; i < n; ++i)
        {
            if (num[i] + sum[i] != s)
            {
                x = false;
                break;
            }
        }
        if (x)
        {
            for (int i = 0; i < n; ++i)
            {
                int temp = s;
                for (int j = 0; j < n; ++j)
                {
                    if (t[i][j] > 0)
                        temp -= t[i][j];
                }
                for (int j = 0; j < n; ++j)
                {
                    if (t[i][j] > 0)
                        cout << t[i][j];
                    else cout << temp;
                    if (j != n - 1)
                        cout << " ";
                    else cout << endl;
                }
            }
        }
        else cout << -1 << endl;
    }
    return 0;
}