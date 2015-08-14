#include <cstdio>
using namespace std;
int main() {
    int n, m, a;
    scanf("%d%d", &n, &m);
    int k = n / 2;
    if (m > k) {
        a = m - 1;
    } else {
        a = m + 1;
    }
    printf("%d\n", a ? a : 1);
    return 0;
}