#include <cstdio>
using namespace std;
int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int ans = 1;
        for (int i = n; i >= 1; --i)
            ans *= i;
        printf("%d\n", ans);
    }
    return 0;
}