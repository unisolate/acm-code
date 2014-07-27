#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int n, p[5], k, ans = 0;
    memset(p, 0, sizeof(p));
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &k);
        p[k]++;
    }
    ans += (p[4] + p[3]);
    p[1] -= p[3];
    ans += p[2] / 2;
    if (p[2] % 2)
    {
        ans++;
        p[1] -= 2;
    }
    if (p[1] < 0)
        p[1] = 0;
    ans += p[1] / 4;
    if (p[1] % 4)
        ans++;
    printf("%d\n", ans);
    return 0;
}