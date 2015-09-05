#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[128];
int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<ll> v;
        for (int i = 0; i < n; ++i) {
            scanf("%I64d", a + i);
            for (ll j = 2; j * j <= a[i]; ++j) {
                while (a[i] % j == 0) {
                    v.push_back(j);
                    a[i] /= j;
                }
            }
            if (a[i] != 1)
                v.push_back(a[i]);
        }
        ll ans;
        sort(v.begin(), v.end());
        if (v.size() < 2) {
            ans = -1;
        } else {
            ans = v[0] * v[1];
        }
        printf("%I64d\n", ans);
    }
    return 0;
}