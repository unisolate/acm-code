#include <bits/stdc++.h>
#define MX 111111
using namespace std;
int f[MX];
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d%d", &l, &r, &d);
    for (int i = 1; i <= k; ++i)
        scanf("%d%d", &x, &y);
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    return 0;
}