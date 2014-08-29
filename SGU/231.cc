#include <bits/stdc++.h>
#define MX 1000001
using namespace std;
bool prime[MX];
int main()
{
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i)
        if (!prime[i])
            for (int j = i + i; j <= n; j += i)
                prime[j] = true;
    for (int i = 4; i <= n; ++i)
        if (!prime[i - 2] && !prime[i])
            ++ans;
    printf("%d\n", ans);
    for (int i = 4; i <= n; ++i)
        if (!prime[i - 2] && !prime[i])
            printf("2 %d\n", i - 2);
    return 0;
}