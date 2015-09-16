#include <cstdio>
#include <algorithm>
#define eps 0.0000001
using namespace std;
double a, b;
int main() {
    scanf("%lf%lf", &a, &b);
    if (a < b) {
        puts("-1");
    } else {
        double x = a + b, y = a - b;
        int u = x / b, v = y / b;
        if (u % 2 == 1)
            --u;
        if (v % 2 == 1)
            --v;
        double c = x / u, d = y / v;
        printf("%.9lf\n", min(c, d));
    }
    return 0;
}