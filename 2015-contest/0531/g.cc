#include <cstdio>
using namespace std;
int main() {
    int t, a, b, cas = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &a, &b);
        long long ans = 0;
        for (int i = 10; i < 100; ++i) {
            printf("%d %d\n", i, (i / 10) * 2 + i % 10);
        }
        printf("Case #%d: %lld\n", ++cas, ans);
    }
    return 0;
}