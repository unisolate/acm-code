#include <cstdio>
#include <algorithm>
#define MX 100010
using namespace std;
int h[MX], a[MX];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", h + i);
    }
    int v = h[n - 1];
    a[n - 1] = 0;
    for (int i = n - 2; i >= 0; --i) {
        if (v >= h[i]) {
            a[i] = v - h[i] + 1;
        } else {
            a[i] = 0;
        }
        v = max(v, h[i]);
    }
    printf("%d", a[0]);
    for (int i = 1; i < n; ++i) {
        printf(" %d", a[i]);
    }
    puts("");
    return 0;
}