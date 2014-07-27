#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 55555
using namespace std;
struct cow
{
    int w, s;
} c[MAXN];
int cmp(cow a, cow b)
{
    int x = a.w + a.s, y = b.w + b.s;
    return x < y;
}
int main()
{
    int n, sum = 0, ans;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &c[i].w, &c[i].s);
    sort(c, c + n, cmp);
    ans = -c[0].s;
    for (int i = 0; i < n; ++i)
    {
        if (sum - c[i].s > ans)
            ans = sum - c[i].s;
        sum += c[i].w;
    }
    printf("%d\n", ans);
    return 0;
}