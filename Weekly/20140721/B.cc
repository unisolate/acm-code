#include <bits/stdc++.h>
#define MAXN 800080
using namespace std;
struct order
{
    int q, d;
} j[MAXN];
int cmp(struct order a, struct order b)
{
    return a.d < b.d;
}
int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d%d", &j[i].q, &j[i].d);
        sort(j, j + n, cmp);
        int s = 0;
        priority_queue<int> p;
        for (int i = 0; i < n; ++i)
            if (s + j[i].q <= j[i].d)
                p.push(j[i].q), s += j[i].q;
            else if (!p.empty() && p.top() > j[i].q)
            {
                s = s - p.top() + j[i].q;
                p.push(j[i].q);
                p.pop();
            }
        printf("%d\n", p.size());
        if (t)
            putchar(10);
    }
    return 0;
}