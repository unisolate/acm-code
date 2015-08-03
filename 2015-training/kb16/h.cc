#include <cstdio>
#include <cstring>
using namespace std;
int m, p[1024000], v[1024000];
char a[1024000];
void kmp() {
    p[0] = -1;
    int i = 0, j = -1;
    while (i < m) {
        if (j == -1 || a[i] == a[j]) {
            ++i, ++j, p[i] = j;
        } else {
            j = p[j];
        }
    }
}
int main() {
    while (~scanf("%s", a)) {
        m = strlen(a);
        kmp();
        int k = 0;
        while (p[m]) {
            v[k++] = m;
            m = p[m];
        }
        v[k++] = m;
        printf("%d", v[k - 1]);
        for (int i = k - 2; i >= 0; --i)
            printf(" %d", v[i]);
        puts("");
    }
    return 0;
}