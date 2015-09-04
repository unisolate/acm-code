#include <cstdio>
#define MX 10001
using namespace std;
typedef long long ll;
int n, m, x, y;
ll c[MX];
int main() {
    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &x, &y);
        ++c[x];
        ++c[y];
    }
    ll ans = 2 * m;
    for (int i = 1; i <= n; ++i) {
        ans += c[i] * (c[i] - 1);
    }
    printf("%I64d\n", ans);
    return 0;
}