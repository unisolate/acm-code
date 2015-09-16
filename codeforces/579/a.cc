#include <cstdio>
using namespace std;
int main() {
    int x, a = 0;
    scanf("%d", &x);
    while (x) {
        a += x & 1;
        x >>= 1;
    }
    printf("%d\n", a);
    return 0;
}