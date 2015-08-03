#include <cstdio>
#include <cstring>
#define MX 100010
#define ls l,m,n<<1     // lson
#define rs m+1,r,n<<1|1 // rson
#define lc n<<1         // lchild
#define rc n<<1|1       // rchild
using namespace std;
typedef long long ll;
ll b, p, c[MX << 2], s[MX];
int N, q, x, y;
char o[9];
void U(int l = 1, int r = N, int n = 1) {
    if (l == r) {
        c[n] = y;
        return;
    }
    int m = (l + r) >> 1;
    if (x <= m) U(ls);
    else U(rs);
    c[n] = (c[lc] * s[r - m] + c[rc]) % p;
}
ll Q(int l = 1, int r = N, int n = 1) {
    if (x <= l && r <= y) {
        return c[n] * s[y - r];
    }
    ll ans = 0;
    int m = (l + r) >> 1;
    if (x <= m) ans += Q(ls);
    if (m < y) ans += Q(rs);
    return ans % p;
}
int main() {
    while (scanf("%lld%lld%d%d", &b, &p, &N, &q) && b + p + N + q) {
        s[0] = 1;
        for (int i = 1; i <= N; ++i)
            s[i] = (s[i - 1] * b) % p;
        memset(c, 0, sizeof(c));
        while (q--) {
            scanf("%s%d%d", o, &x, &y);
            if (o[0] == 'E') {
                U();
            } else {
                printf("%lld\n", Q());
            }
        }
        puts("-");
    }
    return 0;
}