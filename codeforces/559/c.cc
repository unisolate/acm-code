#include <cstdio>
using namespace std;
int cal(int n) {
    int ret = n;
    for (int i = n - 1; i >= 1; --i)
        ret += i * 2;
    return ret;
}
int main() {
    int a[6];
    for (int i = 0; i < 6; ++i)
        scanf("%d", a + i);
    int ans = 0, k = a[0] + a[1] + a[2];
    ans = cal(k);
    for (int i = 0; i < 6; i += 2)
        ans -= cal(a[i]);
    printf("%d\n", ans);
    return 0;
}