#include <cstdio>
#include <algorithm>
#define MX 500500
using namespace std;
int lis[MX];
struct block
{
    int l, m;
} p[MX];
int cmp(struct block a, struct block b)
{
    if (a.l == b.l)
        return a.m < b.m;
    return a.l < b.l;
}
bool c(int a, int b)
{
    return a <= b;
}
int main()
{
    int n, cas = 1;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
            scanf("%d%d", &p[i].l, &p[i].m);
        sort(p, p + n, cmp);
        int j, x, len = 0;
        for (int i = 0; i < n; ++i)
        {
            x = p[i].m;
            j = lower_bound(lis + 1, lis + len + 1, x, c) - lis;
            lis[j] = x;
            len = max(len, j);
        }
        printf("Case %d:\n", cas++);
        printf("My king, at most %d road%s can be built.\n\n", len, (len == 1 ? "" : "s"));
    }
    return 0;
}