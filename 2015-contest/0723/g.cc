#include <cstdio>
#include <algorithm>
#define MX 1000001
using namespace std;
int t, n, m;
int a[MX];
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
    }
    return 0;
}