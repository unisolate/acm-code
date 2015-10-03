#include <bits/stdc++.h>
#define MX 1000010
using namespace std;
struct ele
{
    int p, v;
} e[MX];
int pre[MX], pos[MX];
int main()
{
    int n, t;
    long long ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &e[i].v);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &pos[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &t), e[t].p = i, pre[i] = t;
    for (int i = 1; i < n; ++i)
    {
        if (pre[i] != pos[i])
        {
            // printf("%d %d\n", pre[i], pos[i]);
            ans += e[pre[i]].v + e[pos[i]].v;
            pre[e[pos[i]].p] = pre[i];
        }
    }
    printf("%lld\n", ans);
    return 0;
}