#include <cstdio>
#include <cstring>
using namespace std;
int n, t, j, v, p[111];
void shift(int l) {
    while (p[l] > 9) {
        p[l] %= 10;
        ++p[++l];
    }
}
void dfs(int l) {
    if (l && p[l] == 0)
        return;
    for (int i = 0; i <= 9; ++i) {
        if (!(i + l))
            continue;
        t = ((n * i) % 10 + p[l]) % 10;
        if (t == 0 || t == 1) {
            printf("#%d %d\n", i, t);
            v = n * i, j = l;
            while (v) {
                p[j] += v % 10;
                shift(j++);
                v /= 10;
            }
            dfs(l + 1);
            printf("%d", p[l]);
            return;
        }
    }
}
int main() {
    while (scanf("%d", &n), n) {
        memset(p, 0, sizeof(p));
        dfs(0);
        puts("");
    }
    return 0;
}