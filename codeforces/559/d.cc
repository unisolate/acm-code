#include <cstdio>
#include <cstring>
#define MX 200002
using namespace std;
char a[MX], b[MX];
typedef unsigned long long ull;
const ull B = 100000007ULL;
ull ha[MX], hb[MX], ba[MX] = {1ULL}, bb[MX] = {1ULL};
ull ga(int pos, int l) {
    return ha[pos + l - 1] - ha[pos - 1] * ba[l];
}
ull gb(int pos, int l) {
    return hb[pos + l - 1] - hb[pos - 1] * bb[l];
}
bool dfs(int pa, int pb, int l) {
    if (ga(pa, l) == gb(pb, l))
        return true;
    if (l % 2) return false;
    return (dfs(pa, pb + l / 2, l / 2) && dfs(pa + l / 2, pb, l / 2))
           || (dfs(pa, pb, l / 2) && dfs(pa + l / 2, pb + l / 2, l / 2));
}
int main() {
    scanf("%s%s", a, b);
    int l = strlen(a);
    ha[0] = a[0];
    for (int i = 1; i < l; ++i)
        ha[i] = ha[i - 1] * B + a[i], ba[i] = ba[i - 1] * B;
    hb[0] = b[0];
    for (int i = 1; i < l; ++i)
        hb[i] = hb[i - 1] * B + b[i], bb[i] = bb[i - 1] * B;
    if (dfs(0, 0, l))
        puts("YES");
    else puts("NO");
    return 0;
}