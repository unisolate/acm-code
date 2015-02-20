#include <cstdio>
#include <cstring>
#include <algorithm>
#define MX 1024
using namespace std;
int n, x, cnt, p[MX], t[MX], m[26];
char s[MX];
bool q[MX];
int main() {
    for (int i = 2; i < MX; ++i) {
        if (!t[i])
            p[cnt++] = i;
        for (int j = 0; j < cnt && p[j]*i < MX; ++j) {
            t[i * p[j]] = 1;
            if (i % p[j] == 0)
                break;
        }
    }
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; ++i)
        ++m[s[i] - 'a'];
    int a = m[0], b = 'a', v = 0;
    for (int i = 0; i < 26; ++i)
        if (m[i] > a)
            a = m[i], b = i + 'a', v = i;
    for (int i = 0; i < cnt && p[i] <= n; ++i) {
        if (p[i] * 2 > n)
            ++x, q[p[i] - 1] = true;
    }
    bool f = true;
    if (a < n - x - 1)
        f = false;
    if (f) {
        puts("YES");
        int u = 0;
        q[0] = true;
        for (int i = 0; i < n; ++i) {
            if (q[i]) {
                while (u < 26 && (u == v || m[u] == 0))
                    ++u;
                if (u == 26)
                    putchar(b);
                else putchar(u + 'a');
                --m[u];
            }
            else putchar(b);
        }
    } else puts("NO");
    return 0;
}