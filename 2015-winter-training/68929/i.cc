#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char x[10240], y[1024000];
int a, b, p, r, u[26][10240], v[26];
int main() {
    scanf("%s%s", x, y);
    for (; x[a] != '\0'; ++a) {
        int t = x[a] - 'a';
        u[t][v[t]++] = a;
    }
    b = strlen(y);
    for (int i = 0; i < b; ++i) {
        int t = y[i] - 'a';
        if (v[t] == 0) {
            puts("-1");
            return 0;
        }
        if (u[t][v[t] - 1] < p) {
            p = u[t][0] + 1;
            ++r;
        } else {
            p = *lower_bound(u[t], u[t] + v[t], p) + 1;
            if (p == a)
                p = 0, ++r;
        }
    }
    printf("%d", r + (p ? 1 : 0));
    return 0;
}