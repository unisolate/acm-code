#include <cstdio>
#include <cstring>
using namespace std;
char s[333];
int main()
{
    while (~scanf("%s", s))
    {
        int n = strlen(s), ans = 0, k = 0;
        for (int i = 1; i < n; ++i)
        {
            if ((s[i] == 'B' && s[k] == 'S') || (s[i] == 'B' && s[k] == 'S') || (s[i] == 'B' && s[k] == 'S') || (s[i] == 'B' && s[k] == 'S'))
                ++ans;
        }
        printf("%d\n", ans);
    }
    return 1;
}