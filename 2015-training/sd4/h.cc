#include <cstdio>
#define MX 50050
using namespace std;
int n, m, l, r, a, b;
int p[MX];
int main() {
    int t, cas = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
            scanf("%d", &p[i]);
        printf("Case #%d:\n", ++cas);
        while (m--) {
            scanf("%d%d%d%d", &l, &r, &a, &b);
        }
    }
    return 0;
}