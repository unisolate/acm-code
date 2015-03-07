#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
int p[32][32];
bool f[32];
inline int get(unsigned int k, int i) {
    return k >> i & 0x1;
}
inline unsigned int modi(unsigned int k, int i) {
    return k | (0x1 << i);
}
int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        memset(f, false, sizeof(f));
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &p[i][j]);
        int a = 0;
        unsigned int k = 0;
        queue<unsigned int> q;
        map<unsigned int, int> mp;
        q.push(k);
        while (!q.empty()) {
            k = q.front();
            q.pop();
            int c = 0, d = 0;
            for (int i = 0; i < n; ++i) {
                if (!get(k, i)) {
                    ++c, d = i;
                    int s = 0;
                    for (int j = 0; j < n; ++j) {
                        if (!get(k, j))
                            s += p[i][j];
                    }
                    if (s > 0) {
                        unsigned int z = modi(k, i);
                        if (!mp[z]) {
                            mp[z] = 1;
                            q.push(z);
                        }
                    }
                }
            }
            if (c == 1)
                f[d] = true;
        }
        for (int i = 0; i < n; ++i)
            if (f[i])
                ++a;
        if (a) {
            for (int i = 0; i < n; ++i)
                if (f[i])
                    printf("%d ", i + 1);
            puts("");
        } else puts("0");
    }
    return 0;
}