#include <cstdio>
#include <algorithm>
#include <cmath>
#define MX 100010
using namespace std;
int n;
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    // int x, y;
    // x = min(a, b);
    // a -= x, b -= x;
    // y = (a + b) / 2;
    // printf("%d %d\n", x, y);
    int x = min(a, b), y = a - b;
    if (y < 0)
        y = -y;
    if (y % 2 == 0) {
        y /= 2;
    } else {
        y = (y - 1) / 2;
    }
    printf("%d %d\n", x, y);
    return 0;
}