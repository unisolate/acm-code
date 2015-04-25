#include <cstdio>
#include <cstring>
#define MX 1024
using namespace std;
int m, n, p[MX];
char a[MX], b[MX];
void init() {
    p[0] = -1;
    int i = 0, j = -1;
    while (i < n)
        if (j == -1 || b[i] == b[j])
            ++i, ++j, p[i] = j;
        else j = p[j];
}
int kmp() {
    int i = 0, j = 0, ans = 0;
    while (i < m) {
        if (j == -1 || b[j] == a[i])
            ++i, ++j;
        else j = p[j];
        if (j == n)
            ++ans, j = 0;
    }
    return ans;
}
int main() {
    while (scanf("%s", a) && a[0] != '#' && scanf("%s", b)) {
        m = strlen(a);
        n = strlen(b);
        init();
        printf("%d\n", kmp());
    }
    return 0;
}