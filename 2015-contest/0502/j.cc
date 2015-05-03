#include <cstdio>
#include <map>
#include <cmath>
using namespace std;
int n, q, l, r, a;
int p[1024];
int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; ++i) p[i] = 1;
        map<pair<int, int>, int> mp;
        bool f = true;
        for (int i = 0; i < q; ++i) {
            scanf("%d%d%d", &l, &r, &a);
            if (f) {
                pair<int, int> pr = make_pair(l, r);
                if (mp[pr] && mp[pr] != a) {
                    f = false;
                } else {
                    mp[pr] = a;
                    for (int j = l; j <= r; ++j)
                        p[j] = a * p[j] / gcd(a, p[j]);
                }
            }
        }
        if (f) {
            printf("%d", p[1]);
            for (int i = 2; i <= n; ++i)
                printf(" %d", p[i]);
            puts("");
        } else puts("Stupid BrotherK!");
    }
    return 0;
}