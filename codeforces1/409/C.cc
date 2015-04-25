#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ans = 1000, p[5], x[5] = {1, 1, 2, 7, 4};
    for (int i = 0; i < 5; ++i)
        scanf("%d", &p[i]), ans = min(ans, p[i] / x[i]);
    printf("%d\n", ans);
    return 0;
}