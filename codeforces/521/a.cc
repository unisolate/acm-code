#include <cstdio>
#include <algorithm>
using namespace std;
int n;
long long a, p[256];
char s[102400];
int main() {
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; ++i)
        ++p[s[i]];
    for (int i = 0; i < 256; ++i)
        a = max(a, p[i]);
    a = a * n * n % 1000000007;
    printf("%lld\n", a);
    return 0;
}