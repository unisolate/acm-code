#include <bits/stdc++.h>
using namespace std;
int c[111];
void U(int n)
{
    for (; n < 111; n += (n & -n))
        ++c[n];
}
int Q(int n)
{
    int s = 0;
    for (; n > 0; n -= (n & -n))
        s += c[n];
    return s;
}
int main()
{
    int t, n, p;
    scanf("%d", &t);
    while (t--)
    {
        memset(c, 0, sizeof(c));
        int ans = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &p), ans += Q(n) - Q(p), U(p);
        printf("Optimal train swapping takes %d swaps.\n", ans);
    }
    return 0;
}