#include <cstdio>
#include <algorithm>
#define MX 1000001
using namespace std;
typedef long long ll;
ll p[MX], d[MX][20];
void init(int n)
{
    for (int i = 0; i < n; ++i)
        d[i][0] = p[i];
    for (int j = 1; (1 << j) <= n; ++j)
        for (int i = 0; i + (1 << j) - 1 < n; ++i)
            d[i][j] = max(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
}
int rmq(int x, int y)
{
    if (x > y)
        return 0;
    int k = 0;
    while ((1 << (k + 1)) <= y - x + 1)
        ++k;
    return max(d[x][k], d[y - (1 << k) + 1][k]);
}
int main()
{
    int t, n, k, s;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n, &k, &s);
        p[0] = s;
        for (int i = 1; i < n; ++i)
            p[i] = (1LL * p[i - 1] * 1103515245 + 12345) % (2147483648LL);
        init(n);
        ll ans = 0;
        for (int i = 0; i <= n - k; ++i)
            ans += rmq(i, i + k - 1);
        printf("%lld\n", ans);
    }
    return 0;
}