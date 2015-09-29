#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
const int mn = 55;
int a[mn], b[mn];
int main() {
    int T, n, m, c, t, l;
    scanf("%d", &T);
    while (T--) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        scanf("%d%d", &n, &m);
        l = 5;
        for (int i = 0; i < n; i++) {
            scanf("%d", &c);
            a[c]++;
            l = max(l, c);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &c);
            b[c]++;
        }
        t = 0;
        for (int i = 5; i <= l; i++) {
            if (a[i] == 0)
                continue;
            while (t < mn && b[t] < a[i])
                t++;
            t++;
        }
        if (t < mn)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}