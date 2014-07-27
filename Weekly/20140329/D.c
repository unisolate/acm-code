#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x[555], y[555], link[555][2];
        cin >> n >> m;
        int sum = 0;
        memset(link, 0, sizeof(link));
        for (int i = 0; i < m; ++i)
        {
            cin >> x[i];
        }
        for (int i = 0; i < m; ++i)
        {
            cin >> y[i];
            bool flag = false;
            int k = 0;
            int mi = x[i] < y[i] ? x[i] : y[i],
                ma = x[i] < y[i] ? y[i] : x[i];
            for (int j = 0; j <= sum; ++j)
            {
                if (link[j][0] == mi && link[j][1] == ma)
                {
                    flag = true;
                    break;
                }
            }
            if (flag == false)
            {
                sum++;
                link[sum][0] = mi;
                link[sum][1] = ma;
            }
        }
        double ans = (double)sum / n;
        printf("%.3lf\n", ans);
    }
    return 0;
}