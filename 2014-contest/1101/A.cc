#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
struct P
{
    ll x, y, d;
} p[3333];
int n;
int cmp(P a, P b)
{
    return a.d < b.d;
}
int B(ll v)
{
    int l = 0, r = n, m;
    while (l <= r)
    {
        m = (l + r) >> 1;
        if (p[m].d == v)
            return m;
        if (p[m].d < v)
            l = m + 1;
        else r = m - 1;
    }
    return -1;
}
int main()
{
    freopen("astronomy.in", "r", stdin);
    freopen("astronomy.out", "w", stdout);
    ll a, b, c;
    int m;
    while (~scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%I64d%I64d", &p[i].x, &p[i].y);
            p[i].d = p[i].x * p[i].x + p[i].y * p[i].y;
        }
        sort(p, p + n, cmp);
        scanf("%d", &m);
        while (m--)
        {
            ll ans = 0;
            scanf("%I64d%I64d%I64d", &a, &b, &c);
            int e = B(a), f = B(b);
            if (e == -1 || f == -1)
                ans = 0;
            else
            {
                int g = e, h = f;
                while (g < n && p[g].d == a)++g;
                while (h < n && p[h].d == b)++h;

                while (e >= 0 && p[e].d == a)--e;
                while (f >= 0 && p[f].d == b)--f;
                ++e; ++f;

                if (e > f) swap(e, f), swap(g, h);
                for (int i = e; i < g; ++i)
                {
                    if (S(f, h)) ++ans;
                    // for (int j = f; j < h; ++j)
                    // {
                    //     if (i >= j)
                    //         continue;
                    //     ll k = (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y);
                    //     if (k == c)
                    //     {
                    //         // printf("%d %d\n", i, j);
                    //         ++ans;
                    //     }
                    // }
                }
            }
            printf("%I64d\n", ans);
        }
    }
    return 0;
}