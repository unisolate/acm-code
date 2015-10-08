#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int t, c = 0, n, m, q, x;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        printf("Case #%d:\n", ++c);
        scanf("%d", &q);
        while (q--) {
            scanf("%d", &x);
            printf("%d\n", min((x - 1) < 0 ? 0 : (x - 1),
                               (n - x + 1 + m) < 0 ? 0 : (n + m + 1 - x)));
        }
    }
    return 0;
}