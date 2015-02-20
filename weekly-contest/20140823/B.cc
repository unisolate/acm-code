#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ll m, n;
    while (~scanf("%lld%lld", &m, &n))
    {
        ll ans;
        if (m % 2 && n % 2)
            ans = 0;
        else if (m % 2 == 0 && n % 2 == 0)
            ans = max(m * (n - 2), n * (m - 2));
        else if (m % 2)
            ans = max((m - 1) * n, m * (n - 2));
        else ans = max((m - 2) * n, m * (n - 1));
        if (ans < 0) ans = 0;
        printf("%lld\n\n", ans);
    }
    return 0;
}