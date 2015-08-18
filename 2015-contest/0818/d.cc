#include <cstdio>
#include <map>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n, m;
int a[128][128], b[128];
map<int, int> p;
ll F(int x) {
    ll r = 1;
    while (x) {
        r = (r * x) % MOD;
        --x;
    }
    return r;
}
int main() {
    while (~scanf("%d%d", &n, &m)) {
        ll ans = 1, k = F(n);
        bool f = false;
        for (int i = 0; i < m; ++i) {
            scanf("%d", &a[i][0]);
            if (a[i][0] == -1) {
                if (!f)
                    f = true;
                else ans = (ans * k) % MOD;
            } else {
                p.clear();
                p[a[i][0]]++;
                for (int j = 1; j < n; ++j) {
                    scanf("%d", &a[i][j]);
                    p[a[i][j]]++;
                }
                if (p.size() != n)
                    ans = 0;
            }
        }
        if (!f) {
            for (int i = 0; i < n; ++i)
                b[i] = i + 1;
            for (int i = m - 1; i >= 0; --i) {
                for (int j = 0; j < n; ++j) {
                    b[j] = a[i][b[j] - 1];
                }
            }
            for (int i = 0; i < n; ++i)
                if (b[i] != i + 1)
                    ans = 0;
        }
        printf("%lld\n", ans % MOD);
    }
    return 0;
}