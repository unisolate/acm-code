#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, ans = 1;
    scanf("%d%d", &n, &m);
    while (n > 0)
    {
        --n;
        if (ans % m == 0)
            ++n;
        ++ans;
    }
    printf("%d", ans - 1);
    return 0;
}