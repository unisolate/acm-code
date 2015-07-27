#include <cstdio>
#include <algorithm>
#include <deque>
#define MX 1000001
using namespace std;
typedef long long ll;
ll p[MX];
int main() {
    int t, n, k, s;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &k, &s);
        p[0] = s;
        for (int i = 1; i < n; ++i)
            p[i] = (1LL * p[i - 1] * 1103515245 + 12345) % (2147483648LL);
        ll ans = 0;
        deque<int> q;
        for (int i = 0; i < n; ++i) {
            while (!q.empty() && (i - q.front() >= k)) {
                q.pop_front();
            }
            while (!q.empty() && p[q.back()] <= p[i]) {
                q.pop_back();
            }
            q.push_back(i);
            if (i >= k - 1)ans += p[q.front()];
        }
        printf("%lld\n", ans);
    }
    return 0;
}