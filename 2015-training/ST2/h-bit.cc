#include <cstdio>
using namespace std;
#define MX 102400
typedef long long ll;
char o[9];
int n, q, l, r;
ll p, b[MX], c[MX];

void U(int x, ll v) {
    for (int i = x; i > 0; i -= (i & -i))
        b[i] += v;
    for (int i = x; i <= n; i += (i & -i))
        c[i] += x * v;
}

ll QB(int x) {
    ll v = 0;
    for (; x <= n; x += (x & -x))
        v += b[x];
    return v;
}

ll QC(int x) {
    ll v = 0;
    for (; x > 0; x -= (x & -x))
        v += c[x];
    return v;
}

ll Q(int x) {
    if (x)
        return QB(x) * x + QC(x - 1);
    return 0;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &p);
        U(i, p);
        if (i > 1) U(i - 1, -p);
    }
    while (q--) {
        scanf("%s%d%d", o, &l, &r);
        if (o[0] == 'Q') {
            printf("%lld\n", Q(r) - Q(l - 1));
        } else {
            scanf("%lld", &p);
            U(r, p);
            if (l > 1) U(l - 1, -p);
        }
    }
    return 0;
}