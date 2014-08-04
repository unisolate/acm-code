#include <bits/stdc++.h>
#define MX 1000010
using namespace std;
long long p[MX];
int main()
{
    int n;
    long long a = 0, b = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &p[i]);
    sort(p, p + n);
    bool f = true;
    for (int i = n - 1; i >= 0; --i)
    {
        if (i == 0 || p[i] != p[i - 1])
        {
            if (f)
                a += p[i];
            else b += p[i];
            f = !f;
        }
    }
    printf("%lld\n", a - b);
    return 0;
}