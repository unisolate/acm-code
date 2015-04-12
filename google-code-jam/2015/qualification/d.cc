#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    freopen("D-small-attempt2.in", "r", stdin);
    freopen("D-small-attempt2.out", "w", stdout);
    int t, cas = 0, x, r, c;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &x, &r, &c);
        if (r < c)
            swap(r, c);
        bool f = true;
        if ((r * c) % x)
            f = false;
        for (int i = 1; i <= x - x / 2; ++i) {
            if (x - i + 1 > r || i > c)
                f = false;
        }
        if (x == 4 && r == 4 && c == 2)
            f = false;
        printf("Case #%d: ", ++cas);
        if (f) puts("GABRIEL");
        else puts("RICHARD");
    }
    return 0;
}

// 4 4 2