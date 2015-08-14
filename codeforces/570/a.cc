#include <cstdio>
using namespace std;
typedef long long ll;
ll v[128][128], u[128];
int p[128];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x = 0;
        ll y = 0;
        for (int j = 0; j < n; ++j) {
            scanf("%lld", &v[i][j]);
            if (v[i][j] > y) {
                x = j;
                y = v[i][j];
            }
        }
        u[i] = x;
        p[x]++;
    }
    int x = 0;
    ll y = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i] > y) {
            x = i;
            y = p[i];
        }
    }
    printf("%d\n", x + 1);
    return 0;
}