#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
int p[5555];
int u[256];
int main() {
    u['a'] = u['b'] = u['c'] = 2;
    u['d'] = u['e'] = u['f'] = 3;
    u['g'] = u['h'] = u['i'] = 4;
    u['j'] = u['k'] = u['l'] = 5;
    u['m'] = u['n'] = u['o'] = 6;
    u['p'] = u['q'] = u['r'] = u['s'] = 7;
    u['t'] = u['u'] = u['v'] = 8;
    u['w'] = u['x'] = u['y'] = u['z'] = 9;
    int t, n, m;
    char s[9];
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        map<int, int> mp;
        for (int i = 0; i < n; ++i)
            scanf("%d", p + i);
        for (int i = 0; i < m; ++i) {
            scanf("%s", s);
            int k = 0, l = strlen(s), v = 1;;
            for (int j = l - 1; j >= 0; --j) {
                k += (u[s[j]]) * v;
                v *= 10;
            }
            // printf("#%d\n", k);
            ++mp[k];
        }
        for (int i = 0; i < n; ++i) {
            printf("%d\n", mp[p[i]]);
        }
    }
    return 0;
}