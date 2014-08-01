#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    char a[100], b[100];
    scanf("%s%s", a, b);
    int m = strlen(a), n = strlen(b);
    long long ans = 0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            ans += (a[i] - '0') * (b[j] - '0');
    printf("%I64d\n", ans);
    return 0;
}