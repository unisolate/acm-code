#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
char c[111];
int main()
{
    freopen("a.out", "w", stdout);
    freopen("a.in", "r", stdin);
    int l = 0;
    while (~scanf("%s", c))
    {
        int len = strlen(c);
        for (int i = 3; i < len - 4; ++i)
        {
            bool f = true;
            if (isupper(c[i]))
                continue;
            for (int j = -3; j <= 3; ++j)
            {
                if (j == 0)
                    continue;
                if (islower(c[i + j]))
                    f = false;
            }
            if (i - 4 >= 0 && isupper(c[i - 4]))
                f = false;
            if (i + 4 < len && isupper(c[i + 4]))
                f = false;
            if (f)
                printf("%c", c[i]);
        }
        ++l;
    }
    return 0;
}