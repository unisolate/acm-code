//简化版n皇后 不需考虑斜行
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    long long ans = 0;
    scanf("%d%d", &n, &k);
    if (k <= n)
    {
        ans = 1;
        for (int i = n - k + 1; i <= n; ++i)
            ans *= (i * i);
        for (int i = 1; i <= k; ++i)
            ans /= i;
    }
    printf("%lld\n", ans);
    return 0;
}