#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[111111], a[111111], b[111111];
int p[10], q[10], w[10];
int main()
{
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; ++i)
        ++p[s[i] - '0'];
    for (int i = 0; i < 10; ++i)
        q[i] = p[i];
    int k = 0, f = 0;
    bool flag = false;
    for (int i = 1; i < 10; ++i) {
        --p[i], --q[10 - i];
        if (p[i] < 0 || q[10 - i] < 0) {
            ++p[i], ++q[10 - i];
            continue;
        }
        flag = true;
        int m = 0;
        for (int j = 0; j < 10; ++j) {
            m += min(p[j], q[9 - j]);
        }
        if (m >= k) k = m, f = i;
        ++p[i], ++q[10 - i];
    }
    if (flag) {
        // printf("%d\n", f);
        --p[f], --q[10 - f];
        for (int i = 0; i < 10; ++i) {
            w[i] = min(p[i], q[9 - i]);
            p[i] -= w[i], q[9 - i] -= w[i];
        }
        int u = 0, v = 0;
        for (int i = 9; i > 0; --i) {
            for (int j = 0; j < p[i]; ++j)
                a[u++] = i + '0';
            for (int j = 0; j < q[i]; ++j)
                b[v++] = i + '0';
        }
        if (p[0] > q[0]) a[u++] = '0';
        else if (p[0] < q[0]) b[v++] = '0';
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < w[i]; ++j) {
                a[u++] = i + '0', b[v++] = 9 - i + '0';
            }
        }
        a[u++] = f + '0', b[v++] = 10 - f + '0';
        for (int i = 0; i < min(p[0], q[0]); ++i)
            a[u++] = '0', b[v++] = '0';
    } else {
        int u = 0;
        for (int i = 0; i < n; ++i)
            if (s[i] != '0')
                a[u] = b[u] = s[i], ++u;
        for (int i = 0; i < p[0]; ++i)
            a[u] = b[u] = '0', ++u;
    }
    for (int i = 0; i < n; ++i)
        putchar(a[i]);
    putchar(10);
    for (int i = 0; i < n; ++i)
        putchar(b[i]);
    return 0;
}