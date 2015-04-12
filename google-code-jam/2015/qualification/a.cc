#include <cstdio>
#include <cstring>
using namespace std;
char p[1024];
int k[1024];
int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int t, cas = 0, s;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%s", &s, p);
        for (int i = 0; i <= s; ++i)
            k[i] = p[i] - '0';
        int ans = 0, tot = 0;
        for (int i = 0; i <= s; ++i) {
            if (tot < i) {
                ans += i - tot;
                tot = i;
            }
            tot += k[i];
        }
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}