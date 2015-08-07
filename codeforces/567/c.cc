#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
ll x[200020];
map<ll, vector<int> > m;
int main() {
	// printf("%d\n",(-5)%(2));
    int n;
    ll k;
    scanf("%d%I64d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", x + i);
        m[x[i]].push_back(i);
    }
    ll ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        // if (x[i] < 0) {

        // } else {
            if (x[i] % k == 0 && m[x[i] / k].size() && m[x[i] * k].size()) {
                // printf("%ld %ld\n", (lower_bound(m[x[i] / k].begin(), m[x[i] / k].end(),
                //                                  i) - m[x[i] / k].begin()) ,
                //        (m[x[i] * k].end() - upper_bound(m[x[i] * k].begin(), m[x[i] * k].end(), i)));
                ans += (ll)(lower_bound(m[x[i] / k].begin(), m[x[i] / k].end(),
                                    i) - m[x[i] / k].begin()) *
                       (m[x[i] * k].end() - upper_bound(m[x[i] * k].begin(), m[x[i] * k].end(), i));
            }
        // }
    }
    printf("%I64d\n", ans);
    return 0;
}