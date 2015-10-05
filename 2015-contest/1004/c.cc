#include <cstdio>
#include <cmath>
using namespace std;
const double eps = 1e-8;
double l[1024];
int dblcmp(double d) {
    if (fabs(d) < eps)
        return 0;
    return d > eps ? 1 : -1;
}
int main() {
    int n, s = 0;
    double a = 0.0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", l + i);
        a += l[i];
    }
    a /= n;
    for (int i = 0; i < n; ++i) {
        if (dblcmp(l[i] - a) > 0) {
            ++s;
        }
    }
    printf("%d\n", s);
    return 0;
}