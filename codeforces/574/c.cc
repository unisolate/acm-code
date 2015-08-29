#include <cstdio>
using namespace std;
int a[100001];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        while (a[i] % 2 == 0) {
            a[i] /= 2;
        }
        while (a[i] % 3 == 0) {
            a[i] /= 3;
        }
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1]) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}