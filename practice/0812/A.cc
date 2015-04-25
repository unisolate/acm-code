#include <bits/stdc++.h>
#define MX 1111111
using namespace std;
int p[MX];
int main()
{
    int n;
    scanf("%d", &n);
    // for (int i = 0; i <= n; ++i)
    // {
    //     for (int j = 0; j <= n; ++j)
    //         printf("%2d ", i ^ j);
    //     putchar(10);
    // }
    memset(p, -1, sizeof(p));
    printf("%I64d\n", (long long)n * (n + 1));
    for (int i = 20; i >= 0; --i)
    {
        int t;
        for (int j = 0; j <= n; ++j)
        {
            if (p[j] == -1)
            {
                t = ((1 << i) - 1)^j;
                if (t <= n && p[t] == -1)
                    p[j] = t, p[t] = j;
            }
        }
    }
    for (int i = 0; i <= n; ++i)
        printf("%d ", p[i]);
    return 0;
}