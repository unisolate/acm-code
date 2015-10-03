#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    char s[111];
    scanf("%s", s);
    int ans = 1, c = 0;
    for (int i = 1; i < strlen(s); ++i)
    {
        if (s[i] == s[i - 1])
        {
            c++;
            if (c > 4)
            {
                c = 0;
                ans++;
            }
        }
        else
        {
            c = 0;
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}