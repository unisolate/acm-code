#include <cstdio>
#include <cstring>
#include <algorithm>
#define MX 99999
using namespace std;
typedef long long ll;
struct P
{
    int v, w, i;
} p[MX];
int c[MX];
int x(P a, P b)
{
    return a.v < b.v;
}
int y(P a, P b)
{
    return a.i > b.i;
}
void U(int i)
{
    for (; i < MX; i += i & -i)++c[i];
}
int Q(int i)
{
    int r = 0;
    for (; i > 0; i -= i & -i)r += c[i];
    return r;
}
int main()
{
    int n, k;
    while (~scanf("%d", &n))
    {
        ll a = 0; k = 1; memset(c, 0, sizeof(c));
        for (int i = 0; i < n; ++i)scanf("%d", &p[i].v), p[i].i = i;
        sort(p, p + n, x);
        p[0].w = k;
        for (int i = 1; i < n; ++i)p[i].w = p[i].v == p[i - 1].v ? k : ++k;
        sort(p, p + n, y);
        for (int i = 0; i < n; ++i)a += Q(p[i].w - 1), U(p[i].w);
        printf("%lld\n", a);
    }
    return 0;
}