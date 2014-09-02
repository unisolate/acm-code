#include <cstdio>
#include <cstdlib>
using namespace std;
bool m[181];
int main()
{
    int x = -1, y = -1, a;
    for (int i = 0; i <= 720; ++i)
    {
        ++x;
        if (x >= 60) x -= 60;
        if (i % 5 == 0) ++y;
        if (y >= 60) y -= 60;
        int d = abs(x - y) * 6;
        if (d > 180) d = 360 - d;
        m[d] = true;
    }
    while (~scanf("%d", &a))
    {
        if (m[a])puts("Y");
        else puts("N");
    }
    return 0;
}