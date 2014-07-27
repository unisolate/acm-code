#include <cstdio>
#include <algorithm>
#define MAXN 100010
using namespace std;
int p[MAXN], n, nm;
bool c(int x)
{
    int t = 0;
    for (int i = 0; i < n; ++i)
    {
        t += n + p - lower_bound(p, p + n, p[i] + x);
        if (t == 0) break;
    }
    return t > nm;
}
int main()
{
    while (~scanf("%d", &n))
    {
        nm = n * (n - 1) / 4;
        for (int i = 0; i < n; ++i)
            scanf("%d", &p[i]);
        sort(p, p + n);
        int l = 0, r = p[n - 1] - p[0], m;
        while (r - l > 1)
        {
            m = (l + r) >> 1;
            if (c(m))
                l = m;
            else r = m;
        }
        printf("%d\n", l);
    }
    return 0;
}