#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main()
{
    int x, y, z, n;
    scanf("%d%d%d", &x, &y, &n);
    switch (n % 6)
    {
    case 0:
        z = (x - y) % MOD;
        if (x - y < 0)
            z = MOD + z;
        if (z == MOD)
            z = 0;
        break;
    case 1:
        z = x % MOD;
        if (x < 0)
            z = MOD + z;
        if (z == MOD)
            z = 0;
        break;
    case 2:
        z = y % MOD;
        if (y < 0)
            z = MOD + z;
        if (z == MOD)
            z = 0;
        break;
    case 3:
        z = (y - x) % MOD;
        if (y - x < 0)
            z = MOD + z;
        // if (z == MOD)
        //     z = 0;
        break;
    case 4:
        z = (-x) % MOD;
        if (-x < 0)
            z = MOD + z;
        if (z == MOD)
            z = 0;
        break;
    case 5:
        z = (-y) % MOD;
        if (-y < 0)
            z = MOD + z;
        if (z == MOD)
            z = 0;
        break;
    }
    printf("%d\n", z);
    return 0;
}
/*
1000000000 -7
3
*/