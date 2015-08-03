#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int m, p[1024000];
char a[1024000];
void kmp() {
    p[0] = -1;
    int i = 0, j = -1, ans = m;
    while (i < m) {
        if (j == -1 || a[i] == a[j]) {
            ++i, ++j, p[i] = j;
            if (p[i] && i % (i - p[i]) == 0) {
                ans = min(ans, i - p[i]);
                // printf("%d %d\n", i, i / (i - p[i]));
            }
        } else {
            j = p[j];
        }
    }
    printf("%d\n", (m - p[m]));
}
int main() {
    while (~scanf("%s", a)) {
        m = strlen(a);
        kmp();
    }
    return 0;
}