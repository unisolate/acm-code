#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[99][99];
char p[9];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%s", s[i]);
    int ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j + 1 < m; ++j) {
            p[0] = s[i][j];
            p[1] = s[i][j + 1];
            p[2] = s[i + 1][j];
            p[3] = s[i + 1][j + 1];
            sort(p, p + 4);
            if (p[0] == 'a' && p[1] == 'c' && p[2] == 'e' && p[3] == 'f')
                ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}