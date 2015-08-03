#include <cstdio>
#include <cstring>
using namespace std;
int m, n, p[10240];
int a[1024000], b[10240];
void init() {
    p[0] = -1;
    int i = 0, j = -1;
    while (i < n)
        if (j == -1 || b[i] == b[j])
            ++i, ++j, p[i] = j;
        else j = p[j];
}
int kmp() {
    int i = 0, j = 0;
    while (i < m) {
        if (j == -1 || b[j] == a[i])
            ++i, ++j;
        else j = p[j];
        if (j == n)
            return i - j + 1;
    }
    return -1;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &m, &n);
        for (int i = 0; i < m; ++i)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i)
            scanf("%d", &b[i]);
        init();
        printf("%d\n", kmp());
    }
    return 0;
}