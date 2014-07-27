#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int p = 0, q = 0, r = 0;
    for (int i = 1; i <= 6; ++i)
    {
        int x = a - i, y = b - i;
        if (x < 0)
            x = -x;
        if (y < 0)
            y = -y;
        if (x < y)
            ++p;
        else if (x == y)
            ++q;
        else ++r;
    }
    printf("%d %d %d\n", p, q, r);
    return 0;
}