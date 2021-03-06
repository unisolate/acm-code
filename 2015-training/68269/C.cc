#include <cstdio>
#include <cstring>
#include <algorithm>
#define MX 204800
using namespace std;
char s[MX];
int t, n, l, r, a, d, v, u, m[256], c[MX], p[MX], q[MX];
int main() {
    m['a']=m['e']=m['i']=m['o']=m['u']=m['A']=m['E']=m['I']=m['O']=m['U']=1;
    scanf("%s", s);
    n = strlen(s);
    for (int i = 1; i <= n; ++i)
        c[i] += c[i - 1] + (m[s[i - 1]] ? -1 : 2);
    for (int i = n; i >= 0; --i) {
        if (t == 0 || c[i] > q[t]) {
            q[++t] = c[i];
            p[t] = i;
        }
        l = 1, r = t;
        while (l <= r) {
            d = l + r >> 1;
            if (q[d] >= c[i]) {
                a = d;
                r = d - 1;
            } else l = d + 1;
        }
        v = max(v, p[a] - i);
    }
    for (int i = 1; i <= n - v + 1; ++i)
        if (c[i + v - 1] - c[i - 1] >= 0) ++u;
    if (v) printf("%d %d", v, u);
    else puts("No solution");
    return 0;
}