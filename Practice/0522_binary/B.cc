#include <cstdio>
#include <algorithm>
#include <functional>
#define MAXN 55555
#define INF 500000000
using namespace std;
int n, sum[MAXN], cow[MAXN];
struct cow
{
    int w, s;
} c[MAXN];
int cmp(struct cow a, struct cow b)
{
    int x = a.w + a.s, y = b.w + b.s;
    return x > y;
}
bool ok(int k)
{
    int pos = 1;
    while (pos <= n && cow[pos] >= sum[n] - sum[pos - 1] - k)
        pos = upper_bound(cow + pos, cow + n + 1, sum[n] - sum[pos - 1] - k, greater<int>()) - cow;
    return pos > n;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &c[i].w, &c[i].s);
    sort(c + 1, c + n + 1, cmp);
    for (int i = 1; i <= n; ++i)
    {
        sum[i] = sum[i - 1] + c[i].w;
        cow[i] = c[i].w + c[i].s;
    }
    int l = -INF, r = INF, m;
    while (l + 1 < r)
    {
        m = (l + r) >> 1;
        ok(m) ? r = m : l = m;
    }
    printf("%d\n", r);
    return 0;
}