#include <cstdio>
#include <cstring>
using namespace std;
int n, u;
double m[256], p[555555], q[555555];
char s[555555];
int main() {
    double ans = 0.0;
    m['Y'] = m['A'] = m['E'] = m['I'] = m['O'] = m['U'] = 1.0;
    scanf("%s", s);
    n = strlen(s), u = n / 2;
    for (int i = 1; i <= n; ++i) {
        p[i] += p[i - 1] + m[s[i - 1]];
    }
    for (int i = 1; i <= u; ++i) {
        q[i] += q[i - 1] + m[s[i - 1]] * (i);
    }
    for (int i = u + 1; i <= n; ++i) {
        q[i] += q[i - 1] + m[s[i - 1]] * (n - i + 1);
    }
    // for (int i = 1; i <= n; ++i) {
    //     printf("%d %d\n", p[i], q[i]);
    // }
    for (int i = 1; i <= u; ++i) {
        ans += (q[i - 1] + q[n] - q[n - i + 1] + (p[n - i + 1] - p[i - 1]) * i) / i;
    }
    for (int j = u + 1; j <= n; ++j) {
        int i = n - j + 1;
        ans += (q[i - 1] + q[n] - q[n - i + 1] + (p[n - i + 1] - p[i - 1]) * i) / j;
    }
    printf("%lf", ans);
    return 0;
}