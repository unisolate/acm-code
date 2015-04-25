#include <cstdio>
#include <algorithm>
#define MAXN 50050
using namespace std;
int len, n, m, d[MAXN];
bool C(int x)
{
    int l = 0, c;
    for (int i = 1; i <= n - m + 1; ++i)
    {
        c = l + 1;
        while (c <= n + 1 && d[c] - d[l] < x)
            c++;
        if (c == n + 2)
            return false;
        l = c;
    }
    return true;
}
int main()
{
    scanf("%d%d%d", &len, &n, &m);
    d[0] = 0; d[n + 1] = len;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &d[i]);
    sort(d, d + n + 2);
    int l = 0, r = len + 1, mid;
    while (r - l > 1)
    {
        mid = (l + r) >> 1;
        if (C(mid))
            l = mid;
        else r = mid;
    }
    printf("%d\n", l);
    return 0;
}