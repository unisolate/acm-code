#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int x[3], y[3];
int main() {
    int s = 0, sx = 0;
    for (int i = 0; i < 3; ++i) {
        scanf("%d%d", x + i, y + i);
        if (x[i] > y[i])
            swap(x[i], y[i]);
        s += x[i] * y[i];
        sx += x[i];
    }
    int n = sqrt(s);
    bool f = (n * n == s);
    bool a = (sx == n);
    int cnt = 0;
    for (int i = 0; i < 3; ++i) {
        if (y[i] == n) {
            ++cnt;
        }
    }
    if (cnt != 3) {
        a = false;
    }
    int u = -1, v = 0;
    if (!a) {
        for (int i = 0; i < 3; ++i) {
            if (y[i] == n) {
                if (u != -1) {
                    f = false;
                    break;
                }
                u = i;
                v = n - x[u];
            }
        }
        int ss = 0;
        for (int i = 0; i < 3; ++i) {
            if (i == u)
                continue;
            if (x[i] == v) {
                ss += y[i];
            } else {
                ss += x[i];
            }
        }
        if (ss != n) {
            f = false;
        }
    }
    if (f && (a || u != -1)) {
        printf("%d\n", n);
        if (a) {
            char c = 'A';
            for (int i = 0; i < n; ++i) {
                if (i >= x[0]) {
                    c = 'B';
                }
                if (i >= x[0] + x[1]) {
                    c = 'C';
                }
                for (int j = 0; j < n; ++j) {
                    putchar(c);
                }
                puts("");
            }
        } else {
            char c = 'A' + u;
            for (int i = 0; i < x[u]; ++i) {
                for (int j = 0; j < n; ++j) {
                    putchar(c);
                }
                puts("");
            }
            for (int i = x[u]; i < n; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (j == u)
                        continue;
                    if (x[j] == v) {
                        for (int k = 0; k < y[j]; ++k) {
                            putchar('A' + j);
                        }
                    } else {
                        for (int k = 0; k < x[j]; ++k) {
                            putchar('A' + j);
                        }
                    }
                }
                puts("");
            }
        }
    } else {
        puts("-1");
    }
    return 0;
}