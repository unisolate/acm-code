#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int t, p, x;
    double v, a, b, c, k, ans;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%lf", &p, &x, &v);
        b = tan(v);
        a = b * p / (x * x - 2 * x * p);
        c = -p * (2 * a * x + b);
        k = 2 * a * x + b;
        ans = a * x * x * x / 3 + b * x * x / 2 + k * p * p / 2 + c * p - k * x * x / 2
              - c * x;
        printf("%.3lf\n", round(ans * 1000) / 1000);
    }
    return 0;
}