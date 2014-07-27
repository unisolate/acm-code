#include <cstdio>
#include <algorithm>
#define MX 10010
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
    int n;
    while (~scanf("%d", &n) && n)
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
        printf("%d\n", len);
    }
    puts("*");
    return 0;
}