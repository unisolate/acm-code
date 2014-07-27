#include <cstdio>
#include <cstring>
#define MAXN 111111
using namespace std;
int c[MAXN];
void update(int n, int v)
{
    for (; n <= MAXN; n += (n & -n))
        c[n] += v;
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
    int n, l, r;
    while (scanf("%d", &n) && n)
    {
        memset(c, 0, sizeof(c));
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &l, &r);
            update(l, 1);
            update(r + 1, -1);
        }
        for (int i = 1; i < n; ++i)
            printf("%d ", read(i));
        printf("%d\n", read(n));
    }
    return 0;
}