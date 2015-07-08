#include <cstdio>
#define MX 2048
using namespace std;
int x[MX], y[MX];
int main() {
    int n;
    long long ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &x[i], &y[i]);
    for (int i = 0; i < n - 2; ++i)
        for (int j = i + 1; j < n - 1; ++j)
            for (int k = j + 1; k < n; ++k) {
                if ((y[i] - y[j]) * (x[j] - x[k]) != (y[j] - y[k]) * (x[i] - x[j]))
                    ++ans;
            }
    printf("%lld\n", ans);
    return 0;
}
/*
y   y
- = -
x   x
*/