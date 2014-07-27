#include <cstdio>
#include <algorithm>
#define MX 100010
using namespace std;
int lis[MX], k[MX];
struct sb
{
    int l, r, id;
} p[MX];
int cmp(sb a, sb b)
{
    if (a.l == b.l)
        return a.r > b.r;
    return a.l < b.l;
}
int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d%d", &p[i].l, &p[i].r), p[i].id = i + 1;
        sort(p, p + n, cmp);
        int j, x, len = 0;
        for (int i = 0; i < n; ++i)
        {
            x = p[i].r;
            j = lower_bound(lis + 1, lis + len + 1, x) - lis;
            lis[j] = x;
            k[j] = p[i].id;
            len = max(len, j);
        }
        printf("%d\n", len);
        for (int i = 0; i <= len - 1; ++i)
            printf("%d ", k[i]);
        printf("%d\n\n", k[len]);
    }
    return 0;
}