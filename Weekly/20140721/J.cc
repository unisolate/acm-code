#include <cstdio>
#include <cstring>
#define MOD 1000000007
using namespace std;
char s[11111];
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", s);
        int len = strlen(s), ans = 1;
        int i = 0;
        while (i < len && s[i] == '?')
            ++i;
        for (; i < len; ++i)
        {
            if (s[i] == '?')
            {
                int k = 0;
                while (i + k < len && s[i + k] == '?')
                    ++k;
                if (i + k >= len)
                    break;
                if (s[i - 1] != s[i + k])
                    ans = (ans * (k + 1)) % MOD;
                i += k;
            }
        }
        printf("%d\n", ans % MOD);
    }
    return 0;
}