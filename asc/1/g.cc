#include <cstdio>
#include <algorithm>
#define MX 100010
using namespace std;
struct P {
    int d, s, b;
} p[MX];
int lis[MX], pos[MX], ans[MX];
bool cmp(P x, P y) {
    if (x.s == y.s)
        return x.b > y.b;
    return x.s < y.s;
}
int main() {
    freopen("people.in", "r", stdin);
    freopen("people.out", "w", stdout);
    int n, c = 0, x, len = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        p[i].d = i;
        scanf("%d%d", &p[i].s, &p[i].b);
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1, j; i <= n; ++i) {
        x = p[i].b;
        j = lower_bound(lis + 1, lis + len + 1, x) - lis;
        lis[j] = x;
        pos[i] = j;
        // printf("%d\n", j);
        len = max(len, j);
    }
    printf("%d", len);
    bool f = false;
    x = len;
    for (int i = n; i >= 1; --i) {
        if (x == pos[i]) {
            ans[x] = p[i].d;
            --x;
        }
    }
    for (int i = 1; i <= len; ++i) {
        printf("%c%d", f ? ' ' : '\n', ans[i]);
        f = true;
    }
    puts("");
    return 0;
}