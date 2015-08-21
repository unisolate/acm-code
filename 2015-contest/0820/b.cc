#include <cstdio>
#include <iostream>
#define MX 1000010
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
ll ans[MX];
int p[MX], q[MX];
bool f[MX];
int main() {
    int t, n;
    int cnt = 0;
    for (int i = 2; i < MX; i++) {
        if (!f[i]) {
            p[cnt++] = i;
            q[i] = i;
            for (ll j = i; j < MX; j *= i) {
                q[j] = i;
            }
        }
        for (int j = 0; j < cnt && p[j] * i < MX; j++) {
            f[i * p[j]] = true;
            if (i % p[j] == 0)
                break;
        }
    }

    // while(1){
    // 	scanf("%d",&t);
    // 	printf("%d\n",q[t]);
    // }

    ans[1] = 1;
    for (int i = 2; i < MX; ++i) {
        if (q[i]) {
            ans[i] = (ans[i - 1] * q[i]) % MOD;
        } else ans[i] = ans[i - 1];

        // if (q[i]) {
        //     ans[i] = (ans[i - 1] * (i - 1) * q[i] / i) % MOD;
        // } else ans[i] = (ans[i - 1] * (i - 1) / i) % MOD;
    }

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        ++n;
        while (ans[n] % n) {
            ans[n] += MOD;
        }
        printf("%lld\n", ans[n] / n);
    }
    return 0;
}