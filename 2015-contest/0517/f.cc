#include <cstdio>
#include <cmath>
#define MX 1600
using namespace std;
double ans[MX];
int main() {
    ans[1] = 1.0;
    ans[3] = 2.0;
    double x = 4.0;
    for (int i = 5; i < MX; i += 2) {
        ans[i] = (ans[i - 2] - ans[i - 4]) / x * (x - 1) + ans[i - 2];
        x += 2.0;
    }
    for (int i = 2; i < MX; i += 2) {
        ans[i] = (ans[i - 1] + ans[i + 1]) / 2;
    }
    int t, cas = 0, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("Case %d: %.6lf\n", ++cas, round(ans[n] * 1000000) / 1000000);
    }
    return 0;
}