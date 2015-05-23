#include <cstdio>
#include <queue>
#include <map>
using namespace std;
queue<int> a, b;
map<queue<int>, int> mpa, mpb;
int main() {
    int n, x, y, u, v;
    scanf("%d", &n);
    scanf("%d", &x);
    for (int i = 0; i < x; ++i) {
        scanf("%d", &u);
        a.push(u);
    }
    scanf("%d", &y);
    for (int i = 0; i < y; ++i) {
        scanf("%d", &v);
        b.push(v);
    }
    int ans = 0, f = 0;
    mpa[a] = mpb[b] = 1;
    while (1) {
        if (a.front() > b.front()) {
            a.push(b.front());
            a.push(a.front());
            a.pop();
            b.pop();
        } else {
            b.push(a.front());
            b.push(b.front());
            a.pop();
            b.pop();
        }
        if (mpa[a] && mpb[b]) {
            f = -1;
            break;
        }
        mpa[a] = 1;
        mpb[b] = 1;
        ++ans;
        if (a.size() == n) {
            f = 1;
            break;
        }
        if (b.size() == n) {
            f = 2;
            break;
        }
    }
    if (f > 0)
        printf("%d %d\n", ans, f);
    else printf("%d\n", f);
    return 0;
}