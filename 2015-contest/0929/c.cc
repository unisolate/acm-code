#include <cstdio>
#include <cstring>
using namespace std;
char s[2222];
int p[2222];
int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        memset(p, 0, sizeof(p));
        scanf("%d", &n);
        scanf("%s", s);
        int ans = 0, l = strlen(s);
        for (int i = 0; i < l; ++i) {
            if (s[i] == '*') {
                p[i] = p[i + 1] = p[i + 2] = 1;
            }
        }
        int c = 0;
        for (int i = 1; i <= l; ++i) {
            if (p[i] == 0) {
                ++c;
            } else {
                ans += c / 3;
                if (c % 3)
                    ++ans;
                c = 0;
            }
        }
        ans += c / 3;
        if (c % 3)
            ++ans;
        printf("%d\n", ans);
    }
    return 0;
}