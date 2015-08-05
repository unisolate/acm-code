#include <cstdio>
#include <cstring>
#define MX 200020
using namespace std;
int n, m, a, b, v, p[MX], s[MX];
int F(int x) {
    if (p[x] == -1) return x;
    int k = F(p[x]);
    s[x] += s[p[x]];
    return p[x] = k;
}
int main() {
    while (~scanf("%d%d", &n, &m)) {
        memset(p, -1, sizeof(p));
        memset(s, 0, sizeof(s));
        int c = 0;
        while (m--) {
            scanf("%d%d%d", &a, &b, &v);
            --a;
            int x = F(a), y = F(b);
            if (x == y) {
                if (s[b] - s[a] != v)
                    ++c;
            } else {
                p[y] = x;
                s[y] = s[a] - s[b] + v;
            }
        }
        printf("%d\n", c);
    }
    return 0;
}