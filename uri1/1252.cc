#include <bits/stdc++.h>
using namespace std;
struct s
{
    int x, y;
} p[11111];
int cmp(s a, s b)
{
    if (a.y == b.y)
    {
        int p = abs(a.x % 2), q = abs(b.x % 2);
        if (p == q)
        {
            if (p == 1)
                return a.x > b.x;
            else return a.x < b.x;
        }
        return p > q;
    }
    return a.y < b.y;
}
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) && n + m)
    {
        for (int i = 0; i < n; ++i)
            scanf("%d", &p[i].x), p[i].y = p[i].x % m;
        sort(p, p + n, cmp);
        printf("%d %d\n", n, m);
        for (int i = 0; i < n; ++i)
            printf("%d\n", p[i].x);
    }
    puts("0 0");
    return 0;
}