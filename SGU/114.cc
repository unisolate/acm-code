//找中位数即可
#include <bits/stdc++.h>
#define MX 15015
using namespace std;
struct city
{
    double x;
    long long k;
} p[MX];
bool cmp(city a, city b)
{
    return a.x < b.x;
}
int main()
{
    int n;
    long long s = 0, t = 0;
    double ans;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lf%lld", &p[i].x, &p[i].k), s += p[i].k;
    sort(p, p + n, cmp);
    for (int i = 0; i < n; ++i)
    {
        t += p[i].k;
        if (t > s / 2)
        {
            ans = p[i].x;
            break;
        }
    }
    printf("%.5lf\n", ans);
    return 0;
}