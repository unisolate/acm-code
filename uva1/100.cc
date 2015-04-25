#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y;
    while (~scanf("%d%d", &x, &y))
    {
        int ans = 0;
        for (int i = min(x, y); i <= max(x, y); ++i)
        {
            int a = i, c = 1;
            for (; a != 1; ++c)
            {
                if (a % 2)
                    a = 3 * a + 1;
                else
                    a /= 2;
            }
            ans = max(ans, c);
        }
        printf("%d %d %d\n", x, y, ans);
    }
    return 0;
}
