#include <cstdio>
#include <algorithm>
#define MX 1000010
using namespace std;
struct P {
    int m, l;
} p[MX];
bool cmp(P a, P b) {
    if (a.l == b.l)
        return a.m < b.m;
    return a.l < b.l;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &p[i].m, &p[i].l);
        if (p[i].l != -1) {
            p[p[i].l].m += p[i].m;
        }
    }
    sort(p, p + n, cmp);
    int a = 0, s = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i].l == -1)
            continue;
        if (p[i].l != p[i - 1].l) {
            s = 0;
        } else {
            s += p[i - 1].m;
        }
        a += s;
    }
    printf("%d\n", a);
    return 0;
}