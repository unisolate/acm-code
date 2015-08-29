#include <cstdio>
#include <iostream>
using namespace std;
double a[15], k;
const double eps = 1e-5;
int main() {
    int m, n, ans, cnt;
    while (scanf("%d%d", &n, &m) != EOF) {
        if (m < n) {
            printf("-1\n");
            continue;
        }
        ans = cnt = 0;
        ans += n - 1;
        k = m - n + 1 - eps;
        for (int i = 1; i <= n; i++)
            a[i] = n * 1.0 / i;
        for (int i = 1; i <= n; i++) {
            cnt = k / a[i];
            k -= cnt * a[i];
            ans += cnt;
        }
        cout << ans << endl;
    }
    return 0;
}