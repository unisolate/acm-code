#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int f(int v) {
    int r = 0;
    for (int i = 1; i <= v; ++i) {
        if (v % i && __gcd(i, v) > 1)
            ++r;
    }
    return r;
}
int main() {
    int t, x, y;
    for (int i = 1; i <= 100; ++i) {
        printf("%d %d\n", i, f(i * i) % 2);
    }
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &x, &y);
        int a = 0;
        for (int i = x; i <= y; ++i) {
            if (f(i) % 2)
                ++a;
        }
        printf("%d\n", a);
    }
    return 0;
}