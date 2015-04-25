#include <cstdio>
#include <algorithm>
using namespace std;
int h[231];
int main()
{
    int t, n, p;
    scanf("%d", &t);
    while (t--)
    {
        memset(h, 0, sizeof(h));
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &p), ++h[p];
        bool f = false;
        for (int i = 20; i <= 230; ++i)
        {
            if (h[i])
            {
                if (f) printf(" "); else f = true;
                printf("%d", i);
                for (int j = 1; j < h[i]; ++j)
                    printf(" %d", i);
            }
        }
        putchar(10);
    }
    return 0;
}