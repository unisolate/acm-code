#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int x[3], y[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2},
                     {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
int ans[6][3];
int main() {
    int t, c = 0;
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 3; ++i) {
            scanf("%d", x + i);
        }
        sort(x, x + 3);
        printf("Case #%d:\n", ++c);
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < 6; ++i) {
            bool f = true;
            for (int j = 0; j < i; ++j) {
                bool g = true;
                for (int k = 0; k < 3; ++k) {
                    if (x[y[i][k]] != ans[j][k]) {
                        g = false;
                    }
                }
                if (g) {
                    f = false;
                }
            }
            if (f) {
                printf("%d %d %d\n", x[y[i][0]], x[y[i][1]], x[y[i][2]]);
                for (int j = 0; j < 3; ++j) {
                    ans[i][j] = x[y[i][j]];
                }
            }
        }
    }
    return 0;
}