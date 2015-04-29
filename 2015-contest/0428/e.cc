#include <cstdio>
using namespace std;
long long p[42];
int main() {
    p[1] = p[2] = 1;
    for (int i = 3; i <= 40; ++i) {
        for (int j = 1; j <= i - 1; ++j) {
            long long s = 0;
            for (int k = 1; k <= j; ++k) {
                if (j % k == 0)
                    s += k * p[k];
            }
            p[i] += s * p[i - j];
        }
        p[i] /= i - 1;
    }
    int n;
    while (~scanf("%d", &n)) {
        printf("%lld\n", p[n]);
    }
    return 0;
}
//add(add(d*a(d) for d in divisors(j))*a(n-j) for j in (1..n-1))/(n-1)