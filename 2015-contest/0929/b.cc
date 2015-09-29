#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
const int mx = 1005;
char chr[mx];
int a[mx], b[mx], c[mx];
int main() {
    int T, n, ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%s", &n, chr + 1);
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        ans = 0;
        for (int i = 1; i <= n; i++) {
            a[i] = a[i - 1];
            if (chr[i] == 'S')
                a[i]++;
            if (chr[i] == 'P')
                a[i]--;
        }
        for (int i = 1; i <= n; i++) {
            b[i] = b[i - 1];
            if (chr[i] == 'R')
                b[i]++;
            if (chr[i] == 'S')
                b[i]--;
        }
        for (int i = n; i > 0; i--) {
            c[i] = c[i + 1];
            if (chr[i] == 'P')
                c[i]++;
            if (chr[i] == 'R')
                c[i]--;
        }
        for (int i = 0; i <= n; i++)
            for (int j = i; j <= n; j++) {
                if (a[i] + c[j + 1] + b[j] - b[i] > 0)
                    ans++;
            }
        printf("%d\n", ans);
    }
    return 0;
}