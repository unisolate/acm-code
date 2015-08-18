#include <cstdio>
#include <algorithm>
#define MX 222222
using namespace std;
typedef long long ll;
int a[MX], b[MX], c[MX];
int main() {
    int n;
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", a + i, b + i, c + i);
        }
        printf("%lld\n");
    }
    return 0;
}