#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[20480];
int p[3], x[3], d[3];

int abs(int k) {
    if (k < 0) return -k;
    return k;
}

int main() {
    int ans = 0;
    scanf("%d%d%d", &x[0], &x[1], &x[2]);
    scanf("%s", s);
    sort(x, x + 3);
    int l = strlen(s);
    for (int i = 0; i < l; ++i) {
        if (s[i] == 'R')
            ++p[0];
        else if (s[i] == 'Y')
            ++p[1];
        else ++p[2];
        d[0] = abs(p[0] - p[1]);
        d[1] = abs(p[0] - p[2]);
        d[2] = abs(p[1] - p[2]);
        sort(d, d + 3);
        if (d[0] == x[0] && d[1] == x[1] && d[2] == x[2]) {
            ans = max(ans, p[0] + p[1] + p[2]);
            p[0] = p[1] = p[2] = 0;
        }
    }
    ans = max(ans, p[0] + p[1] + p[2]);
    printf("%d\n", ans);
    return 0;
}