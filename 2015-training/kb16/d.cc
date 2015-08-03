#include <cstdio>
#include <cstring>
using namespace std;
int m, p[102400];
char a[102400];
int init() {
    p[0] = -1;
    int i = 0, j = -1, k;
    while (i < m) {
        if (j == -1 || a[i] == a[j])
            ++i, ++j, p[i] = j;
        else j = p[j];
        if (j == 0) k = i;
    }
    // if (k == 1) return 0;
    if (k == m) return k;
    return k - (m % k == 0 ? k : m % k);
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", a);
        m = strlen(a);
        printf("%d\n", init());
        // for (int i = 0; i < m; ++i)
        //     printf("%d ", p[i]);
        // puts("");
        // printf("%d\n", kmp());
    }
    return 0;
}