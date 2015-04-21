#include <cstdio>
#include <algorithm>
using namespace std;

long long x[4], y[4], z[4];
long long d[6];

int main() {
    int t, cas = 0;
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 4; ++i)
            scanf("%lld%lld%lld", x + i, y + i, z + i);
        bool f = false;
        int k = 0;
        for (int i = 0; i < 4; ++i)
            for (int j = i + 1; j < 4; ++j)
                d[k++] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) +
                         (z[i] - z[j]) * (z[i] - z[j]);
        sort(d, d + 6);
        f = (d[0] == d[1] && d[1] == d[2] && d[2] == d[3] && d[4] == d[5]
             && d[4] == d[0] * 2);
        printf("Case #%d: ", ++cas);
        puts(f ? "Yes" : "No");
    }
    return 0;
}