#include <cstdio>
using namespace std;
int main() {
    int k, n, w;
    scanf("%d%d%d", &k, &n, &w);
    int s = 0;
    for (int i = 1; i <= w; ++i) {
        s += i * k;
    }
    printf("%d\n", (s - n) > 0 ? s - n : 0);
    return 0;
}