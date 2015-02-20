#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int k, pos = 0, flag[256];
    char s[1111], ans[1111];
    scanf("%d%s", &k, s);
    memset(flag, 0, sizeof(flag));
    for (int i = 0; i < strlen(s); ++i)
        flag[s[i]]++;
    for (int i = 'a'; i <= 'z'; ++i)
        if (flag[i] != 0)
            if (flag[i] % k != 0)
            {
                printf("-1\n");
                return 0;
            }
            else
            {
                for (int j = 0; j < flag[i] / k; ++j)
                    ans[pos++] = i;
            }
    for (int i = 0; i < k; ++i)
        for (int j = 0; j < pos; ++j)
            printf("%c", ans[j]);
    putchar(10);
    return 0;
}