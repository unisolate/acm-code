#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas)
    {
        double n, m, a, b;
        scanf("%lf%lf%lf%lf", &n, &m, &a, &b);
        double ans = m + (m - n) * a / b;
        printf("Case #%d: ", cas);
        if (ans >= 0 && ans <= 10)
            printf("%.2lf\n", ans);
        else puts("Impossible");
    }
    return 0;
}