#include <cstdio>
#define MX 555555
using namespace std;
int n, k, x = 0, y = 0;
char p[MX], q[MX];
void r(char *s, int &a) {
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            ++a;
            bool f = true;
            for (int j = 0; j < k; ++j) {
                if ('A' + j != s[i] && (i + 1 == n || ( i + 1 < n && 'A' + j != s[i + 1]))) {
                    s[i] = 'A' + j;
                    f = false;
                    break;
                }
            }
            if (f)
                s[i] = s[i + 1];
        }
    }
}
int main() {
    scanf("%d%d%s", &n, &k, p);
    for (int i = 0; i < n; ++i)
        q[i] = p[n - i - 1];
    if (k == 2) {
        for (int i = 0; i < n; i += 2) {
            if (p[i] != 'A')
                ++x;
            else ++y;
        }
        for (int i = 1; i < n; i += 2) {
            if (p[i] != 'A')
                ++y;
            else ++x;
        }
        if (x < y) {
            printf("%d\n", x);
            for (int i = 0; i < n; ++i)
                putchar('A' + i % 2);
        } else {
            printf("%d\n", y);
            for (int i = 0; i < n; ++i)
                putchar('A' + (i + 1) % 2);
        }
    } else {
        r(p, x);
        r(q, y);
        if (x < y)
            printf("%d\n%s", x, p);
        else {
            printf("%d\n", y);
            for (int i = n - 1; i >= 0; --i)
                putchar(q[i]);
        }
    }
    return 0;
}