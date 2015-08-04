#include <cstdio>
#include <vector>
#include <queue>
#include <set>
using namespace std;
// priority_queue<int, vector<int>, greater<int> > q;
set<int> s;
int main() {
    int n, o, a;
    scanf("%d", &n);
    // while (!q.empty()) q.pop();
    s.clear();
    // ma = 0;
    while (n--) {
        scanf("%d", &o);
        if (o == 1) {
            scanf("%d", &a);
            // q.push(a);
            s.insert(a);
            // if (a > ma) {
            //     ma = a;
            // }
        } else if (o == 2) {
            if (!s.empty()) {
                s.erase(*s.begin());
                // if (q.empty())
                //     ma = 0;
            }
        } else {
            if (!s.empty())
                printf("%d\n", *(--s.end()));
            else puts("0");
        }
    }

    return 0;
}