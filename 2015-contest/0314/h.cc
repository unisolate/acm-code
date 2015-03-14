#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    int n, k;
    double w;
    while (cin >> n >> w >> k) {
        double ans = (n + 2 - (n + 2) / k) * w / 2.0;
        ans = round(ans * 100) / 100;
        printf("%.2lf\n", ans);
        // cout << setprecision(2) << ans << endl;
        // cout << ans << endl;
    }
    return 0;
}