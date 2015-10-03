#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int run(int p)
{
    long long x = 10;
    int ans = 0;
    while (x < p)
        x *= 10;
    x /= 10;
    while (x != 0)
    {
        int k = p / x;
        if (k == 4 || k == 7)
            ans++;
        p -= x * k;
        x /= 10;
    }
    return ans;
}
int main()
{
    int n, k, p, ans = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &p);
        if (run(p) <= k)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}