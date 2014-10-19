#include <cstdio>
#include <cstring>
using namespace std;
char a[111111], b[1111];
int main()
{
    int t, q, x, y;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s%d", a, &q);
        x = strlen(a);
        while (q--)
        {
            scanf("%s", b);
            y = strlen(b);
            bool f = false;
            int k = 0;
            for (int i = 0; i < x; ++i)
            {
                if (a[i] == b[k])
                    ++k;
                if (k == y)
                {
                    f = true;
                    break;
                }
            }
            printf("%s\n", f ? "Yes" : "No");
        }
    }
    return 0;
}