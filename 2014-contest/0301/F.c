#include <stdio.h>
#include <string.h>
#define MAXN 33000
int c[MAXN], level[MAXN];
void update(int n, int v)
{
    for(; n <= MAXN; n += (n & -n))
        c[n] += v;
}
int query(int n)
{
    int sum = 0;
    for(; n > 0; n -= (n & -n))
        sum += c[n];
    return sum;
}
int main()
{
    int n, i, x, y;
    scanf("%d", &n);
    int level[n];
    memset(c, 0, sizeof(c));
    memset(level, 0, sizeof(level));
    for(i = 0; i < n; ++i)
    {
        scanf("%d%d", &x, &y);
        level[query(x + 1)]++;
        update(x + 1, 1);
    }
    for(i = 0; i < n; ++i)
    {
        printf("%d\n", level[i]);
    }
    return 0;
}
