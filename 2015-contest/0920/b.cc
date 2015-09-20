#include <cstdio>
#include <cstring>
using namespace std;
char s[11111], ans[11111];
int main() {
    int t, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%s", &m, s);
        int len = strlen(s), p = 0, l = 0;
        bool mode = false, stat = false;
        for (int i = 0; i < len; ++i) {
            if (s[i] == 'L') {
            } else if (s[i] == 'R') {
            } else if (s[i] == 'S') {
            } else if (s[i] == 'D') {
            } else if (s[i] == 'B') {
            } else if (s[i] == 'C') {
            } else if (s[i] == 'V') {
            } else {
            }
        }
        printf("%s\n", ans);
    }
    return 0;
}