#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
            printf("%2d ", i ^ j);
        putchar(10);
    }
    return 0;
}
