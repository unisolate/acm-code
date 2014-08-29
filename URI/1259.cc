#include <bits/stdc++.h>
using namespace std;
int p[111111], q[111111];
int main()
{
    int n, t, x = 0, y = 0;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &t);
        if (t % 2) p[x++] = t;
        else q[y++] = t;
    }
    sort(p, p + x), sort(q, q + y);
    for (int i = 0; i < y; ++i)
        printf("%d\n", q[i]);
    for (int i = x - 1; i >= 0; --i)
        printf("%d\n", p[i]);
    return 0;
}