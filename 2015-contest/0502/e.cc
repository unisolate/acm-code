#include <cstdio>
using namespace std;
int n, m, x[256];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; ++i)
            scanf("%d", x + i);
    }
    return 0;
}