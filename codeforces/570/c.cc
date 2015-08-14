#include <cstdio>
using namespace std;
char p[333333], o[9];
int main() {
    int n, m, u = 0, x = 0;
    scanf("%d%d%s", &n, &m, p + 1);
    bool f = false;
    for (int i = 1; i <= n + 1; ++i) {
        if (p[i] == '.') {
            if (!f) {
                f = true;
                u = i;
            }
        } else {
            if (f) {
                x += i - u - 1;
                f = false;
            }
        }
    }
    while (m--) {
        scanf("%d%s", &u, o);
        if (o[0] == '.') {
            if (p[u] != '.') {
                if (u - 1 > 0 && p[u - 1] == '.') {
                    ++x;
                }
                if (u + 1 <= n && p[u + 1] == '.') {
                    ++x;
                }
                p[u] = '.';
            }
        } else {
            if (p[u] == '.') {
                if (u - 1 > 0 && p[u - 1] == '.') {
                    --x;
                }
                if (u + 1 <= n && p[u + 1] == '.') {
                    --x;
                }
                p[u] = o[0];
            }
        }
        printf("%d\n", x);
    }
    return 0;
}