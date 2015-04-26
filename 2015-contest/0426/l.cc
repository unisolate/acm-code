#include <cstdio>
using namespace std;
int main() {
    int t, n, p;
    scanf("%d", &t);
    while (t--) {
        int ans = 0;
        scanf("%d", &n);
        while (n--) {
            scanf("%d", &p);
            if (p > 6000)++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}