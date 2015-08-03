#include <cstdio>
#include <map>
using namespace std;
int main() {
    int t, x, y;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &x, &y);
        map<int, int> m;
        int k = 0;
        while (x >= 1) {
            m[x] = ++k;
            x /= 2;
        }
        k = 0;
        while (y >= 1) {
            if (m[y]) {
                printf("%d\n", m[y] + k - 1);
                break;
            }
            ++k;
            y /= 2;
        }
    }
    return 0;
}