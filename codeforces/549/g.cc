#include <cstdio>
#include <algorithm>
#define MX 200200
using namespace std;
long long a[MX];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &a[i]);
    for (int i = 0; i < n - 1; ++i) {
        while (a[i] >= a[i + 1]) {
            if (a[i] == 0 || a[i] == a[i + 1] + 1) {
                puts(":(");
                return 0;
            }
            swap(a[i], a[i + 1]);
            ++a[i];
            --a[i + 1];
        }
    }
    printf("%lld", a[0]);
    for (int i = 1; i < n; ++i)
        printf(" %lld", a[i]);
    printf("\n");
    return 0;
}