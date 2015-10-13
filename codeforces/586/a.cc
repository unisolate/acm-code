#include <cstdio>
#include <algorithm>
#include <cstring>
#define MX 100010
using namespace std;
int a[MX];
int main() {
    int n, ans = 0;
    scanf("%d", &n);
    int c = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n; ++i) {
        if (a[i]) {
            int c = 0;
            for (int j = i + 1; j < n; ++j) {
                if (a[j]) {
                    c = j - i;
                    break;
                }
            }
            if (c <= 2) {
                for (int j = i + 1; j < i + c; ++j) {
                    a[j] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i]) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}