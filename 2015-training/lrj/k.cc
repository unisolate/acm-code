#include <cstdio>
#include <queue>
#include <algorithm>
#define MX 999
using namespace std;
struct P {
    int x;
    int y;
    bool operator<(const P &a) const {
        return x > a.x;
    }
};
int a[MX], b[MX];
int main() {
    int k;
    while (~scanf("%d", &k)) {
        for (int i = 0; i < k; ++i) {
            scanf("%d", a + i);
        }
        sort(a, a + k);
        for (int i = 1; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                scanf("%d", b + j);
            }
            sort(b, b + k);
            priority_queue<P> q;
            for (int j = 0; j < k; ++j) {
                P t; t.x = a[j] + b[0]; t.y = 0;
                q.push(t);
            }
            for (int j = 0; j < k; ++j) {
                P u = q.top();
                q.pop();
                a[j] = u.x;
                if (u.y + 1 < k) {
                    P t; t.x = u.x - b[u.y] + b[u.y + 1]; t.y = u.y + 1;
                    q.push(t);
                }
            }
        }
        for (int i = 0; i < k - 1; ++i)
            printf("%d ", a[i]);
        printf("%d\n", a[k - 1]);
    }
    return 0;
}