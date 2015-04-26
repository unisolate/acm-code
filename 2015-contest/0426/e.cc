#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
ll a, b, c, d;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        for (int i = 1; i <= 20; ++i)
            printf("%lld\n", c * i - d * (ll)floor((double)a / b * i));
    }
    return 0;
}