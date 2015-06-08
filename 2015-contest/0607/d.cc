#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
char s[99];
int get(int l, int r) {
    int ret = 0, t = 1;
    for (int i = r; i >= l; --i) {
        ret += (s[i] - '0') * t;
        t *= 10;
    }
    return ret;
}
int main() {
    while (scanf("%s", s) && s[0] != 'E') {
        int n = strlen(s), ans = 0, l = (1 << n);

        for (int i = 0; i < l; ++i) {
            // printf("#%d\n", i);
            for (int j = 1; j < n; ++j) {
                if ((i >> (j - 1)) & 1) {
                    continue;
                }

                int p = 0, l = 0, r = 0;
                for (int k = 1; k <= j; ++k) {
                    if (((i >> (k - 1)) & 1) || k == j) {
                        // l += atoi(s.substr(p, k - p).c_str());
                        l += get(p, k - 1);
                        // cout << s.substr(p, k - p) << " " << l << endl;
                        p = k;
                    }
                }
                for (int k = j + 1; k <= n; ++k) {
                    if (((i >> (k - 1)) & 1) || k == n) {
                        // r += atoi(s.substr(p, k - p).c_str());
                        r += get(p, k - 1);
                        // cout << s.substr(p, k - p) << " " << r << endl;
                        p = k;
                    }
                }
                // printf("##%d %d\n", l, r);
                if (l == r) ++ans;
            }
        }
        printf("%d\n", ans / 2);
    }
    return 0;
}