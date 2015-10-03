#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
long long tree[1001];
struct line
{
    int n, m;
} p[1001 * 1001];
bool cmp(struct line a, struct line b)
{
    if (a.n == b.n)
        return a.m > b.m;
    else
        return a.n > b.n;
}
void update(int i, int v)
{
    for (; i <= 1000; i += (i & -i))
        tree[i] += v;
}
long long read(int i)
{
    long long sum = 0;
    for (; i > 0; i -= (i & -i))
        sum += tree[i];
    return sum;
}
int main()
{
    int t, i, j, n, m, k;
    long long c;
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        c = 0;
        memset(p, 0, sizeof(p));
        memset(tree, 0, sizeof(tree));
        scanf("%d %d %d", &n, &m, &k);
        for (j = 1; j <= k; j++)
            scanf("%d %d", &p[j].n, &p[j].m);
        sort(p + 1, p + 1 + k, cmp);
        for (j = 1; j <= k; j++)
        {
            c += read(p[j].m - 1);
            update(p[j].m, 1);
        }
        printf("Test case %d: %lld\n", i + 1, c);
    }
    return 0;
}