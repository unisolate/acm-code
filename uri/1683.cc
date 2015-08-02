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