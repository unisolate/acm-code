#include <cstdio>
#include <algorithm>
using namespace std;
struct P {
    int d, t;
} p[100001];
int cmp(P x, P y) {
    return x.t > y.t;
}
int main() {
    int t, n, cas = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int s = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &p[i].d, &p[i].t);
            s += p[i].d;
        }
        sort(p, p + n, cmp);
        int ans = s + p[n - 1].t, k = 0;
        for (int i = 0; i < n; ++i) {
            k += p[i].d;
            if (k + p[i].t > ans)
                ans = k + p[i].t;
        }
        printf("Case %d: %d\n", ++cas, ans);
    }
    return 0;
}