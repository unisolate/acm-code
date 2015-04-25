#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct P
{
    int v, t;
} p[1111];
bool f[1111];
int cmp(P a, P b)
{
    if (a.v == b.v)
        return a.t > b.t;
    return a.v > b.v;
}
int main()
{
    int n, h;
    while (~scanf("%d%d", &n, &h))
    {
        memset(f, false, sizeof(f));
        for (int i = 0; i < n; ++i)
            scanf("%d%d", &p[i].v, &p[i].t);
        sort(p, p + n, cmp);
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int k = p[i].t;
            while (k && f[k]) --k;
            if (k) f[k] = true; else ans += p[i].v;
        }
        printf("%d\n", ans);
    }
    return 0;
}