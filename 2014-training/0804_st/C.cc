#include <bits/stdc++.h>
#define MX 222222
using namespace std;
int c[MX], d[MX];
void update(int n, int v)
{
    for (; n <= MX; n += (n & -n))
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
    int t, m, n, a;
    scanf("%d", &t);
    while (t--)
    {
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
            d[i] = m + i, update(d[i], 1);
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d", &a);
            printf("%d%c", read(d[a] - 1), i == m ? 10 : ' ');
            update(d[a], -1);
            d[a] = m - i + 1;
            update(d[a], 1);
        }
    }
    return 0;
}