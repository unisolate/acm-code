#include <cstdio>
#define MX 222222
#define MOD 530600414
using namespace std;
typedef long long ll;
ll p[MX], q[MX], l[MX], s[MX];
int main() {
    p[3] = p[4] = 0;
    q[3] = 1, q[4] = 1;
    l[3] = 3, l[4] = 5;
    s[3] = 0, s[4] = 2;
    for (int i = 5; i < MX; ++i) {
        // q[i] = q[i - 1] + q[i - 2];
        // l[i] = l[i - 1] + l[i - 2];
        // p[i] = p[i - 1] + p[i - 2] +
        //        q[i - 1] * (q[i - 2] * l[i - 2] - s[i - 2]) +
        //        q[i - 2] * s[i - 1];
        // s[i] = s[i - 2] + s[i - 1] + q[i - 1] * l[i - 2];
        q[i] = (q[i - 1] + q[i - 2]) % MOD;
        l[i] = (l[i - 1] + l[i - 2]) % MOD;
        p[i] =
            (p[i - 1] + p[i - 2] +
             (q[i - 1] * ((q[i - 2] * l[i - 2]) % MOD - s[i - 2] + MOD) % MOD) %
                 MOD +
             (q[i - 2] * s[i - 1]) % MOD) %
            MOD;
        s[i] = (s[i - 2] + s[i - 1] + (q[i - 1] * l[i - 2]) % MOD) % MOD;
    }

    int t, n, c = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("Case #%d: %lld\n", ++c, p[n] % MOD);
    }
    return 0;
}