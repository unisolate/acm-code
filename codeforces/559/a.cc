#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int n, a, m = 10000000;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        m = min(m, a);
    }
    if (m > 1)puts("1");
    else puts("-1");
    return 0;
}