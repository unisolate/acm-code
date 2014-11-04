#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
ll x[3333], y[3333];
int main()
{
    freopen("astronomy.in", "r", stdin);
    freopen("astronomy.out", "w", stdout);
    ll a, b, c;
    int n, m;
    while (scanf("%d", &n) && n)
    {
        map<pair<pair<ll, ll>, ll>, int> mp;
        for (int i = 0; i < n; ++i)
            scanf("%I64d%I64d", &x[i], &y[i]);
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                ++mp[make_pair(make_pair(x[i]*x[i] + y[i]*y[i], x[j]*x[j] + y[j]*y[j]), (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]))];
            }
        scanf("%d", &m);
        while (m--)
        {
            int ans = 0;
            scanf("%I64d%I64d%I64d", &a, &b, &c);
            if (a == b)
                ans = mp[make_pair(make_pair(a, b), c)];
            else ans = mp[make_pair(make_pair(a, b), c)] + mp[make_pair(make_pair(b, a), c)];
            printf("%d\n", ans);
        }
    }
    return 0;
}