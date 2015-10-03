#include <bits/stdc++.h>
#define MX 100010
#define MOD 1000000007LL
using namespace std;
char a[MX];
int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas)
    {
        long long ans = 0, m = 1;
        scanf("%s", a);
        int len = strlen(a), u = len / 2;
        for (int i = 0; i < u; ++i)
        {
            if (a[i] == '1' && a[len - i - 1] == '1')
                ans = (ans + m) % MOD;
            m = (m * 2) % MOD;
            if (a[i] == '1' || a[len - i - 1] == '1')
                ans = (ans + m) % MOD;
            m = (m * 2) % MOD;
        }
        if (len % 2 && a[len / 2] == '1')
            ans = (ans + m) % MOD;
        printf("Case #%d: %lld\n", cas, ans);
    }
    return 0;
}