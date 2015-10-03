#include <bits/stdc++.h>
#define MX 111111
using namespace std;
typedef long long ll;
int n, m, k, l[MX], r[MX], d[MX], x, y;
ll a[MX], add[MX], cnt[MX];
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%I64d", &a[i]);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d%d", &l[i], &r[i], &d[i]);
    for (int i = 1; i <= k; ++i)
    {
        scanf("%d%d", &x, &y);
        ++cnt[x], --cnt[y + 1];
    }
    for (int i = 1; i <= m; ++i)
        cnt[i + 1] += cnt[i];
    for (int i = 1; i <= m; ++i)
    {
        add[l[i]] += (ll)d[i] * cnt[i];
        add[r[i] + 1] -= (ll)d[i] * cnt[i];
    }
    for (int i = 1; i <= n; ++i)
        add[i + 1] += add[i];
    for (int i = 1; i <= n; ++i)
        printf("%I64d ", a[i] + add[i]);
    return 0;
}