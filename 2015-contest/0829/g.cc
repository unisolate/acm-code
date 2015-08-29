#include <cstdio>
#include <cmath>
#define MX 200002
using namespace std;
const long double pi = 3.141592653589793238462643383279502884L;
// long double v[MX];
int main() {
    int n;
    long double r;
    // v[1] = 1 / 2, v[2] = 1 / pi;
    // for (int i = 3; i < MX; i += 2) {
    //     v[i] = v[i - 2] * i / 2 / pi;
    // }
    // for (int i = 4; i < MX; i += 2) {
    //     v[i] = v[i - 2] * i / 2 / pi;
    // }
    while (~scanf("%d%Lf", &n, &r)) {
        long double ans = (n % 2 ? (1 / r) : (4 / pi / r / r));
        for (int i = (n % 2 ? 1 : 2); i < n; i += 2) {
            ans = ans * i * 2 / pi / r / r;
        }
        // printf("%.10Lf\n", ans * v[n] / (n + 1));
        printf("%.10Lf\n", ans / (n + 1));
    }
    return 0;
}