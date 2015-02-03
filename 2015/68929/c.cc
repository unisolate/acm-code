#include <cstdio>
#include <cstring>
#include <algorithm>
#define MX 1024
using namespace std;
char s[MX];
int a, w1, w2, p[MX], t[MX], x[MX], m1[MX], m2[MX], u1[MX], u2[MX];
int main() {
    int cnt = 0;
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
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
        ++m1[s[i]];
    }
    for (int i = 'a'; i <= 'z'; ++i) {
        if (m1[i])
            u1[w1++] = m1[i];
    }
    sort(u1, u1 + w1);
    for (int i = 0; i < cnt && p[i] <= n; ++i) {
        bool f = false;
        int v = a;
        for (int j = p[i]; j <= n; j += p[i]) {
            if (x[j]) {
                f = true;
                v = x[j];
                break;
            }
        }
        if (!f)
            ++a;
        for (int j = p[i]; j <= n; j += p[i])
            x[j] = f ? v : a;
    }
    bool c = true;
    if (a > w1)
        c = false;
    else {
        for (int i = 1; i <= n; ++i)
            ++m2[x[i]];
        sort(m2, m2 + a);
        
    }
    if (c) {
        puts("YES");
    } else puts("NO");
    return 0;
}