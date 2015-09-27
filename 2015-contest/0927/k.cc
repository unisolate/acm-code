#include <cstdio>
#include <cstring>
#include <algorithm>
#define MX 100010
using namespace std;

int n, ans[MX];

struct tree {
    int l, r, n;
} b[MX << 2];

struct P {
    int h, k;
} p[MX];

int cmp(P a, P b) {
    return a.h < b.h;
}

void init() {
    int i, j, k;
    for (k = 1; k < n; k <<= 1)
        ;
    for (i = k; i < 2 * k; i++) {
        b[i].l = b[i].r = i - k + 1;
        b[i].n = 1;
    }
    for (i = k - 1; i > 0; i--) {
        b[i].l = b[2 * i].l;
        b[i].r = b[2 * i + 1].r;
        b[i].n = b[2 * i].n + b[2 * i + 1].n;
    }
}

void insert(int i, int x, int m) {
    if (b[i].l == b[i].r) {
        ans[b[i].l] = m;
        b[i].n = 0;
        return;
    }
    if (x <= b[2 * i].n)
        insert(2 * i, x, m);
    else
        insert(2 * i + 1, x - b[2 * i].n, m);
    b[i].n--;
}

int main() {
    int t, c = 0, i, j;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            ans[i] = 0;
            scanf("%d%d", &p[i].h, &p[i].k);
        }
        sort(p + 1, p + n + 1, cmp);
        printf("Case #%d: ", ++c);
        init();
        for (i = 1; i <= n; ++i) {
            insert(1, p[i].k + 1, p[i].h);
        }
        bool f = true;
        for (i = 1; i <= n; ++i) {
            if (ans[i] == 0) {
                f = false;
                break;
            }
        }
        if (n == 1 && p[1].k) {
            f = false;
        }
        if (f) {
            printf("%d", ans[1]);
            for (i = 2; i <= n; ++i)
                printf(" %d", ans[i]);
            printf("\n");
        } else {
            puts("impossible");
        }
    }
    return 0;
}