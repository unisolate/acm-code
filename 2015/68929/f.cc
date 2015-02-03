#include <cstdio>
#include <algorithm>
#define MX 102400
using namespace std;
int a[MX], b[MX];
int gcd(int a, int b)
{
    return (b ? gcd(b, a % b) : a);
}
int main() {
    int m, n;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i)
        scanf("%d", &b[i]);
    sort(a, a + n);
    sort(b, b + m);
    
    return 0;
}