#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        double a, s = 0.0;
        for (int i = 0; i < 12; ++i) {
            scanf("%lf", &a);
            s += a;
        }
        s = round(s * 100 / 12);
        if ((int)(s) % 100 == 0)
            printf("$%.0lf\n", s / 100);
        else if ((int)(s) % 10 == 0)
            printf("$%.1lf\n", s / 100);
        else printf("$%.2lf\n", s / 100);
    }
    return 0;
}