#include <cstdio>
#include <algorithm>
#define MX 100010
using namespace std;
struct P {
    int a, b;
} p[MX];
int cmpa(P x, P y) {
    return x.a < y.a;
}
int cmpb(P x, P y) {
    return x.b < y.b;
}
int main() {
    int n, k, ans = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i].a);
        ans += p[i].a / 10;
        if (p[i].a < 100) {
            p[i].b = (p[i].a / 10 + 1) * 10 - p[i].a;
        } else {
            p[i].b = 0;
        }
    }
    sort(p, p + n, cmpb);
    for (int i = 0; i < n && k > 0; ++i) {
        if (p[i].b > 0 && k >= p[i].b) {
            k -= p[i].b;
            ++ans;
            p[i].a = p[i].a + p[i].b;
        }
    }
    sort(p, p + n, cmpa);
    for (int i = 0; i < n && k >= 10; ++i) {
        while (p[i].a < 100 && k >= 10) {
            k -= 10;
            p[i].a += 10;
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}