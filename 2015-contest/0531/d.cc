#include <cstdio>
using namespace std;
int main() {
    int t, cas = 0, m, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &m, &n);
        printf("Case #%d: ", ++cas);
        if (m == 2) {
            for (int i = 0; i < n / 2; ++i)
                putchar('a');
            for (int i = n / 2; i < n; ++i)
                putchar('b');
        } else {
            for (int i = 0; i < n; ++i)
                putchar('a' + i % m);
        }
        putchar(10);
    }
    return 0;
}