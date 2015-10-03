#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int p[2048], c;
char a[1024], b[1024];
int main() {
    int n;
    while (~scanf("%d", &n)) {
        memset(p, 0, sizeof(p));
        for (int i = 0; i < n; ++i) {
            scanf("%s%s%d", a, b, &c);
            c = 2 * c + 1;
            if (strlen(b) == 1) {
                if (b[0] == '=') {
                    ++p[c];
                } else if (b[0] == '<') {
                    for (int j = 0; j < c; ++j)
                        ++p[j];
                } else {
                    for (int j = c + 1; j < 2048; ++j)
                        ++p[j];
                }
            } else {
                if (b[0] == '<') {
                    for (int j = 0; j <= c; ++j)
                        ++p[j];
                } else {
                    for (int j = c; j < 2048; ++j)
                        ++p[j];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 2048; ++i) {
            ans = max(ans, p[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}