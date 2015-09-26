#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
double x[3], y[3];
int dblcmp(double d) {
    if (fabs(d) < eps)
        return 0;
    return d > eps ? 1 : -1;
}
double dis(double xa, double ya, double xb, double yb) {
    return (xa - xb) * (xa - xb) + (ya - yb) * (ya - yb);
}
int main() {
    int t, c = 0;
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 3; ++i) {
            scanf("%lf%lf", x + i, y + i);
        }
        double a = dis(x[1], y[1], x[2], y[2]), b = dis(x[0], y[0], x[1], y[1]);
        x[0] = 0.0, y[0] = sqrt(b - a / 4);
        x[1] = -sqrt(a / 4), y[1] = 0.0;
        x[2] = sqrt(a / 4), y[2] = 0.0;
        double ans = y[0];
        double B = acos(x[2] / sqrt(b));
        double r = sqrt(b) / tan(B);
        ans += r * 2 * B;
        printf("Case #%d: %.4lf\n", ++c, ans);
    }
    return 0;
}