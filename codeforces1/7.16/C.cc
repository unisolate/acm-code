#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p[20] = {0LL};
int dfs(ll n, int i)
{
    int k = n / p[i];
    n %= p[i];
    return n ? k * i + min(i + dfs(p[i] - n, i - 1), dfs(n, i - 1)) : k * i;
}
int main()
{
    ll n;
    for (int i = 1; i < 17; ++i)
        p[i] = p[i - 1] * 10 + 1;
    scanf("%lld", &n);
    printf("%d\n", dfs(n, 16));
    return 0;
}