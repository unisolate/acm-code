#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    freopen("A-small-practice.in", "r", stdin);
    freopen("A-small-practice.out", "w", stdout);
    int t, x, y, p, m[20], a[4], v, cas = 0;
    scanf("%d", &t);
    while (t--) {
        v = 0;
        memset(m, 0, sizeof(m));
        scanf("%d", &x);
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j) {
                scanf("%d", &p);
                if (i == x - 1)
                    m[p] = 1;
            }
        scanf("%d", &y);
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j) {
                scanf("%d", &p);
                if (i == y - 1 && m[p])
                    a[v++] = p;
            }
        printf("Case #%d: ", ++cas);
        if (v == 1)
            printf("%d\n", a[0]);
        else if (v > 1)
            puts("Bad magician!");
        else puts("Volunteer cheated!");
    }
    return 0;
}