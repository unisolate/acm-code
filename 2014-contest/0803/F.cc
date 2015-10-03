#include <bits/stdc++.h>
#define MX 500050
using namespace std;
char s[MX];
int main()
{
    int n;
    long long ans = 0;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n - 1; ++i)
    {
        if (s[i] != s[i + 1])
        {
            int add = min(i, n - i - 2);
            for (int j = add; j >= 1; --j)
                if (s[i - j] == s[i + 1 + j])
                    add = j - 1;
            ans += add + 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}