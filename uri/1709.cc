#include <cstdio>
using namespace std;
int main() {
    int x, n;
    while (~scanf("%d", &x)) {
        n = x / 2;
        int k = 1, a = 2;
        while (a != 1) {
            if (a > n) {
                a = 2 * (a - n - 1) + 1;
            } else {
                a = 2 * a;
            }
            ++k;
        }
        printf("%d\n", k);
    }
    return 0;
}