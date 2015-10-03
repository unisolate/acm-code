/* queue */
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

/* stack */
#include <cstdio>
#include <stack>
#define MX 100001
using namespace std;
typedef long long ll;
int h[MX], l[MX], r[MX];
stack<int> s;
int main() {
    int n;
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", h + i);
        }
        while (!s.empty()) s.pop();
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && h[s.top()] >= h[i])
                s.pop();
            l[i] = (s.empty() ? 0 : (s.top() + 1));
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && h[s.top()] >= h[i])
                s.pop();
            r[i] = (s.empty() ? n : s.top());
            s.push(i);
        }
        ll a = 0;
        for (int i = 0; i < n; ++i)
            a = max(a, (ll)h[i] * (r[i] - l[i]));
        printf("%lld\n", a);
    }
    return 0;
}