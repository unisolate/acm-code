#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#define MX 0x7f7f7f7f
using namespace std;
int n, m;
unsigned int x, y;
char s[99];
queue<pair<unsigned int, int> > q;
map<unsigned int, int> mp;
int check(unsigned int v) {
    int r = 0;
    for (int i = 0; i < m; ++i) {
        r += ((0x1 << i) & v) >> i;
    }
    return r;
}
unsigned int cut(unsigned int v, unsigned int z, int p) {
    return v | (z << p);
}
int main() {
    while (~scanf("%d", &n)) {
        scanf("%s", s);
        scanf("%d", &m);
        bool shit = true;
        for (int i = 0; i < n; ++i)
            if (s[i] == '*')
                shit = false;
        if (shit)
            puts("-1");
        else {
            x = y = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == '*') {
                    x = x | (0x1 << i);
                    y = y | (0x1 << (n - i - 1));
                }
            }
            while (!q.empty())
                q.pop();
            mp.clear();
            q.push(make_pair(0, 0));
            int a = -1;
            while (!q.empty()) {
                unsigned int v = q.front().first;
                int t = q.front().second;
                q.pop();
                int c = check(v);
                if (c == m) {
                    a = t;
                    break;
                }
                for (int i = 0; i < m; ++i) {
                    int v1 = cut(v, x, i), v2 = cut(v, y, i);
                    if (check(v1) > c && !mp[v1]) {
                        q.push(make_pair(v1, t + 1));
                        mp[v1]++;
                    }
                    if (check(v2) > c && !mp[v2]) {
                        q.push(make_pair(v2, t + 1));
                        mp[v2]++;
                    }
                }
            }
            printf("%d\n", a);
        }
    }
    return 0;
}