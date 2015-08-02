#include <cstdio>
#include <cstring>
using namespace std;
bool f[10];
bool c(int x) {
    memset(f, false, sizeof(f));
    while (x) {
        if (f[x % 10])
            return false;
        f[x % 10] = true;
        x /= 10;
    }
    return true;
}
int main() {
    int t, a, b;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &a, &b);
        int ans = 0;
        for (int i = a; i <= b; ++i) {
            if (c(i))
                ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}