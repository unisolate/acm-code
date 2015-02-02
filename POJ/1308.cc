#include <cstdio>
#include <map>
#define MX 102400
using namespace std;
int s, t, cas, x[MX], y[MX], c[MX];
bool flag;
map<int, int> p;
int f(int x) {
    return x == c[x] ? x : (c[x] = f(c[x]));
}
bool uni(int x, int y) {
    x = f(x), y = f(y);
    if (x == y) return true;
    --s;
    c[x] = y;
    return false;
}
void init() {
    for (int i = 1; i < MX; ++i)
        c[i] = i;
    p.clear();
    s = t = 0;
    flag = true;
}
int main() {
    init();
    while (scanf("%d%d", &x[t], &y[t]) && x[t] >= 0) {
        if (x[t] == 0) {
            for (int i = 0; i < t; ++i) {
                if (uni(p[x[i]], p[y[i]]))
                    flag = false;
            }
            // printf("%d\n", s);
            if (s > 1)
                flag = false;
            if (flag)
                printf("Case %d is a tree.\n", ++cas);
            else printf("Case %d is not a tree.\n", ++cas);
            init();
        } else {
            if (p[x[t]] == 0)
                p[x[t]] = ++s;
            if (p[y[t]] == 0)
                p[y[t]] = ++s;
            ++t;
        }
    }
    return 0;
}