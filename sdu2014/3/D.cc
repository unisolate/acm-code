#include <bits/stdc++.h>
#define MX 300030
using namespace std;
struct people
{
    int id, v;
} p[MX];
int c1(people a, people b)
{
    return a.v < b.v;
}
int c2(people a, people b)
{
    return a.id < b.id;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &p[i].v);
        p[i].id = i;
    }
    sort(p, p + n, c1);
    for (int i = 1; i < n; ++i)
    {
        if (p[i].v <= p[i - 1].v)
            p[i].v = p[i - 1].v + 1;
    }
    sort(p, p + n, c2);
    for (int i = 0; i < n - 1; ++i)
        printf("%d ", p[i].v);
    printf("%d\n", p[n - 1].v);
    return 0;
}