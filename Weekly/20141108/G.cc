#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;
int p[30001];
int main()
{
    // printf("%d\n", 500000004 * 2);
    int t, n, cas = 0;
    scanf("%d", &t);
    while (t--)
    {
        map<pair<int, int>, int> mp;
        int ans = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &p[i]);
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                if (((long long)p[i]*p[j]) % MOD == 1 && mp[make_pair(min(p[i], p[j]), max(p[i], p[j]))] == 0)
                {
                    ++ans;
                    ++mp[make_pair(min(p[i], p[j]), max(p[i], p[j]))];
                }
            }
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}