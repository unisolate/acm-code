#include <cstdio>
using namespace std;
int main() {
    int n, o, x, cas = 0;
    while (~scanf("%d", &n)) {
        int k = 0;
        printf("Case #%d:\n", ++cas);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &o, &x);
            if (o) {

            } else {
                ++k;
                printf("%d\n");
            }
        }
    }
    return 0;
}