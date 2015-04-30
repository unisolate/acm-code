#include <cstdio>
using namespace std;
int m, p[1024000];
char a[1024000];
void kmp() {
    p[0] = -1;
    int i = 0, j = -1;
    while (i < m) {
        if (j == -1 || a[i] == a[j]) {
            ++i, ++j, p[i] = j;
            if (p[i] && i % (i - p[i]) == 0) {
                printf("%d %d\n", i, i / (i - p[i]));
            }
        } else {
            j = p[j];
        }
    }
}
int main() {
    int cas = 0;
    while (scanf("%d", &m) && m) {
        scanf("%s", a);
        printf("Test case #%d\n", ++cas);
        kmp();
        puts("");
    }
    return 0;
}