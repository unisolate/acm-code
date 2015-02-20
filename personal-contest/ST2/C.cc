#include <cstdio>
#include <algorithm>
#define MX 111111
using namespace std;
typedef long long ll;
struct S
{
    int l, r, i;
} p[MX];
int x[MX], a[MX], f[MX];
ll c[MX], ans[MX];
int cmp(S a, S b)
{
    return a.r < b.r;
}
void U(int x, int v)
{
    for (; x < MX; x += (x & -x))
        c[x] += v;
}
ll Q(int x)
{
    ll s = 0;
    for (; x > 0; x -= (x & -x))
        s += c[x];
    return s;
}
int B(int v, int u)
{
    int l = 0, r = u - 1, m;
    while (l <= r)
    {
        m = (l + r) >> 1;
        if (x[m] == v)
            return m;
        if (x[m] < v)
            l = m + 1;
        else r = m - 1;
    }
    return -1;
}
int main()
{
    int t, n, q, l, r, cnt;
    scanf("%d", &t);
    while (t--)
    {
        memset(c, 0, sizeof(c));
        memset(f, 0, sizeof(f));
        scanf("%d", &n), cnt = n;
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]), x[i - 1] = a[i];
        sort(x, x + cnt);
        cnt = unique(x, x + cnt) - x;
        scanf("%d", &q);
        for (int i = 0; i < q; ++i)
            scanf("%d%d", &p[i].l, &p[i].r), p[i].i = i;
        sort(p, p + q, cmp);
        int k = 0, d;
        for (int i = 1; i <= n; ++i)
        {
            d = B(a[i], cnt);
            if (f[d]) U(f[d], -a[i]);
            U(i, a[i]);
            f[d] = i;
            for (; k < q; ++k)
            {
                if (p[k].r == i)
                    ans[p[k].i] = Q(p[k].r) - Q(p[k].l - 1);
                else break;
            }
        }
        for (int i = 0; i < q; ++i)
            printf("%lld\n", ans[i]);
    }
    return 0;
}