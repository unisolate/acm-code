#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 500050
using namespace std;
int n;
long long x[MAXN], y[MAXN], z[MAXN];
long long check(long long mid)
{
    long long sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (mid < x[i])
            continue;
        sum += (min(mid, y[i]) - x[i]) / z[i] + 1;
    }
    return sum;
}
void solve()
{
    long long l = 0, r = 1LL << 33, mid;
    while (l < r)
    {
        mid = (l + r) >> 1;
        if (check(mid) % 2)
            r = mid;
        else l = mid + 1;
    }
    if (l >= 1LL << 33)
        printf("no corruption\n");
    else printf("%I64d %I64d\n", l, check(l) - check(l - 1));
}
int main()
{
    n = 0;
    char s[111];
    while (gets(s))
    {
        if (strlen(s))
        {
            sscanf(s, "%I64d%I64d%I64d", &x[n], &y[n], &z[n]);
            ++n;
        }
        else if (n)
        {
            solve();
            n = 0;
        }
    }
    if (n)
        solve();
    return 0;
}