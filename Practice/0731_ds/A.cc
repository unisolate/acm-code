#include <cstdio>
#include <algorithm>
#define MX 22222
using namespace std;
typedef long long ll;
ll d[MX], s[MX];
struct cow
{
    ll v, x;
} c[MX];
bool cmp(cow a, cow b)
{
    return a.v < b.v;
}
void update(int n, ll v, ll *bit)
{
    for (; n <= MX; n += (n & -n))
        bit[n] += v;
}
ll read(int n, ll *bit)
{
    int sum = 0;
    for (; n > 0; n -= (n & -n))
        sum += bit[n];
    return sum;
}
int main()
{
    int n;
    ll t = 0, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld%lld", &c[i].v, &c[i].x);
    sort(c, c + n, cmp);
    for (int i = 0; i < n; ++i)
    {
        int l = read(c[i].x, s);
        update(c[i].x, c[i].x, d);
        update(c[i].x, 1, s);
        t = -read(c[i].x - 1, d) + read(MX, d) - read(c[i].x, d);
        ans += c[i].v * (c[i].x * l + t - c[i].x * (i - l));
    }
    printf("%lld\n", ans);
    return 0;
}