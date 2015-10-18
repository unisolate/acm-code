#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#define MX 10010
using namespace std;
struct P {
    int a, b;
} p[MX];
int n, pos, v[MX];
bool cmp(P x, P y) {
    return x.b < y.b;
}
bool ok(int t) {
    ++pos;
    for (int i = 1; i <= n; ++i) {
        int c = 0;
        for (int j = p[i].a; j < p[i].b; ++j) {
            if (c == t) {
                break;
            }
            if (v[j] != pos) {
                v[j] = pos;
                ++c;
            }
        }
        if (c < t) {
            return false;
        }
    }
    return true;
}
void solve(int l, int r) {
    int m;
    while (l + 1 < r) {
        m = (l + r) >> 1;
        ok(m) ? l = m : r = m;
    }
    printf("%d\n", l * n);
}
int main() {
    int l = 10005;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &p[i].a, &p[i].b);
        l = min(l, p[i].b - p[i].a);
    }
    sort(p + 1, p + n + 1, cmp);
    solve(0, 10000);
    return 0;
}