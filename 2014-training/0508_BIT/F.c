#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 111111
using namespace std;
int c[MAXN], a[MAXN];
struct cow
{
    int i, l, r;
} f[MAXN];
int cmp(cow a, cow b)
{
    if (a.r == b.r)
        return a.l < b.l;
    else return a.r > b.r;
}
void update(int n)
{
    for (; n <= MAXN; n += (n & -n))
        c[n]++;
}
int read(int n)
{
    int sum = 0;
    for (; n > 0; n -= (n & -n))
        sum += c[n];
    return sum;
}
int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d%d", &f[i].l, &f[i].r);
            f[i].l++;
            f[i].r++;
            f[i].i = i;
        }
        sort(f + 1, f + n + 1, cmp);
        int l = -1, r = -1;
        for (int i = 1; i <= n; ++i)
        {
            if (f[i].l == l && f[i].r == r)
            {
                a[f[i].i] = a[f[i - 1].i];
            }
            else
            {
                l = f[i].l;
                r = f[i].r;
                a[f[i].i] = read(f[i].l);
            }
            update(f[i].l);
        }
        for (int i = 1; i < n; ++i)
            printf("%d ", a[i]);
        printf("%d\n", a[n]);
    }
    return 0;
}