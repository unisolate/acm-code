#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, x, p[99], q[99], a[999];
int main() {
    while (scanf("%d", &n) && n) {
        bool f = false;
        memset(p, -1, sizeof(p));
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            if (p[x - 1] != -1) f = true;
            p[x - 1] = i;
            q[i] = x - 1;
        }
        if (f) {
            puts("No solution");
            continue;
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            while (p[i] != i) {
                x = q[p[i] - 1];
                a[cnt++] = p[i];
                swap(q[p[i]], q[p[i] - 1]);
                swap(p[i], p[x]);
            }
        }
        printf("%d", cnt);
        for (int i = 0; i < cnt; ++i)
            printf(" %d", a[i]);
        puts("");
    }
    return 0;
}