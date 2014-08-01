#include <bits/stdc++.h>
using namespace std;
int a[5];
char s[100010];
int main()
{
    for (int i = 1; i < 5; ++i)
        scanf("%d", &a[i]);
    scanf("%s", s);
    int l = strlen(s);
    long long ans = 0;
    for (int i = 0; i < l; ++i)
        ans += a[s[i] - '0'];
    printf("%I64d\n", ans);
    return 0;
}