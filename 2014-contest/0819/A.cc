#include <bits/stdc++.h>
#define MX 1111
using namespace std;
typedef long long ll;
ll x[MX], y[MX];
priority_queue<pair<ll, int> > q;
priority_queue<pair<ll, int> >::iterator iter, end;
int main()
{
    int n, m, k, p, a;
    scanf("%d%d%d%d", &n, &m, &k, &p);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            scanf("%d", &a);
            x[i] += a, y[j] += a;
        }
    for (int i = 0; i < n; ++i)
        q.push(make_pair(x[i], 0));
    for (int i = 0; i < m; ++i)
        q.push(make_pair(y[i], 1));
    ll ans = 0;
    while (k--)
    {
        ans += q.top()->first;
        if (q.top()->second)
        {
            q.top()->first -= p * n;
            iter = q.begin();
            end = q.end();
            while (iter != end)
            {
                if (iter->second == 0)
                    iter->first -= p;
                ++iter;
            }
        }
        else
        {
            q.top()->first -= p * m;
            iter = q.begin();
            end = q.end();
            while (iter != end)
            {
                if (iter->second)
                    iter->first -= p;
                ++iter;
            }
        }
    }
    printf("%I64d", ans);
    return 0;
}