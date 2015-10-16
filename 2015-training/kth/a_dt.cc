#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define MX 100010
#define ls l, m, n << 1          // lson
#define rs m + 1, r, n << 1 | 1  // rson
#define lc n << 1                // lchild
#define rc n << 1 | 1            // rchild
using namespace std;

int p[MX], s[20][MX], sum[20][MX];

int main() {
    int m;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", p + i);
        }
        sort(p + 1, p + n + 1);
        while (m--) {
            scanf("%d%d%d");
            printf("%d\n");
        }
    }
    return 0;
}