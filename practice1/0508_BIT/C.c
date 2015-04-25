#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 500010
using namespace std;
int c[MAXN];
struct num
{
    int n, i;
} a[MAXN];
int cmp(num a, num b)
{
    return a.n > b.n;
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
        long long sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i].n);
            a[i].i = i;
        }
        sort(a + 1, a + n + 1, cmp);
        for (int i = 1; i <= n; ++i)
        {
            sum += read(a[i].i);
            update(a[i].i);
        }
        printf("%lld\n", sum);
    }
    return 0;
}