#include <cstdio>
#define MX 1000010
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
ll ans[MX];
ll gcd(ll a, ll b) {
    return a % b ? gcd(b, a % b) : b;
}
int main() {
    int t, n;
    ans[1] = 1;
    for (int i = 2; i < MX; ++i) {
    	
    }
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%lld\n", ans[n]);
    }
    return 0;
}