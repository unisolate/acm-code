#include <bits/stdc++.h>
using namespace std;
int c[111];
void U(int n, int v)
{
    for (; n < 111; n += (n & -n))
        c[n] += v;
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
    int n, l, r;
    while (~scanf("%d", &n))
    {
        memset(c, 0, sizeof(c));
        while (n--)
            scanf("%d%d", &l, &r), U(l, 1), U(r + 1, -1);
        scanf("%d", &n);
        if (Q(n))
        {
            int x = 0;
            for (int i = 1; i < n; ++i)
                x += Q(i);
            printf("%d found from %d to %d\n", n, x, x + Q(n) - 1);
        }
        else printf("%d not found\n", n);
    }
    return 0;
}