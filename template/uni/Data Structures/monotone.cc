// 单调队列
// 利用双端队列实现，在队列中存数组下标。
// 滚动窗口：每次从头弹出不在窗口内的元素，从尾弹出小于新元素的元素，新元素插入到尾。
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
            if (i >= k - 1)
                ans += p[q.front()];
        }
        printf("%lld\n", ans);
    }
    return 0;
}

// 单调栈（最大面积）
// 同样存下标。
// 最大面积：正反扫两遍维护 l, r 数组，表示 h[i] 能向左/右扩展的最大长度。
int h[MX], l[MX], r[MX];
stack<int> s;
int main() {
    int n;
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", h + i);
        }
        while (!s.empty())
            s.pop();
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && h[s.top()] >= h[i])
                s.pop();
            l[i] = (s.empty() ? 0 : (s.top() + 1));
            s.push(i);
        }
        while (!s.empty())
            s.pop();
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