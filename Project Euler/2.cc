#include <cstdio>
int solve()
{
    int x = 1, y = 1, z, sum = 0;
    while (y < 4000000)
    {
        z = y;
        y += x;
        if (y % 2 == 0)
            sum += y;
        x = z;
    }
    return sum;
}
int main()
{
    printf("%d\n", solve());
    return 0;
}