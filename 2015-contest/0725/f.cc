#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <iostream>
using namespace std;
typedef long long ll;
int n, k;
ll v;
priority_queue<ll, vector<ll>, greater<ll> > q;
char o[9];
int main() {
    while (~scanf("%d%d", &n, &k)) {
        while (!q.empty()) q.pop();
        while (n--) {
            scanf("%s", o);
            if (o[0] == 'I') {
                scanf("%lld", &v);
                if (q.size() < k || v > q.top()) {
                    q.push(v);
                    if (q.size() > k)
                        q.pop();
                }
            } else {
                printf("%lld\n", q.top());
            }
        }
    }
    return 0;
}