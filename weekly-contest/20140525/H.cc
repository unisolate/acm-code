#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    char s[111];
    scanf("%s", s);
    bool flag = false;
    int sum = 1;
    for (int i = 1; i < strlen(s); ++i)
    {
        if (s[i] == s[i - 1])
            sum++;
        else sum = 1;
        if (sum == 7)
        {
            flag = true;
            break;
        }
    }
    if (flag)
        printf("YES\n");
    else printf("NO\n");
    return 0;
}