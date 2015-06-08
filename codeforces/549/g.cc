#include <cstdio>
#include <algorithm>
#define MX 200200
using namespace std;
int a[MX];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        a[i] += i;
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
        a[i] -= i;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            puts(":(");
            return 0;
        }
    }
    printf("%d", a[0]);
    for (int i = 1; i < n; ++i)
        printf(" %d", a[i]);
    printf("\n");
    return 0;
}