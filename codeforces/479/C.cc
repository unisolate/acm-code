#include <cstdio>
#include <algorithm>
using namespace std;
int a[5001], b[5001];
struct P
{
    int a, b;
} p[5001];
int cmp(P x, P y)
{
    if (x.a == y.a)
        return x.b < y.b;
    return x.a < y.a;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &p[i].a, &p[i].b);
    sort(p, p + n, cmp);
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (p[i].b >= ans)
            ans = p[i].b;
        else ans = p[i].a;
    }
    printf("%d\n", ans);
    return 0;
}