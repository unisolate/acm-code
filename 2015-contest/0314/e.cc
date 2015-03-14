#include <cstdio>
#define MOD 1000000007
#define MX 100000001
using namespace std;
int n, m, k;
int f[MX], g[MX];
int main() {
    while (~scanf("%d%d%d", &n, &m, &k)) {
        f[1] = m, g[1] = m - 1;
        for (int i = 2; i <= n; ++i) {
            f[i] = (k * g[i - 1] + (m - k) * f[i - 1]) % MOD;
            g[i] = ((k - 1) * g[i - 1] + (m - k) * f[i - 1]) % MOD;
        }
        printf("%d\n", f[n]);
    }
    return 0;
}