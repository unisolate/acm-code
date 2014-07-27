#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    char s[100], t[100];
    scanf("%s%s", s, t);
    int pos = 0, len = strlen(t);
    for (int i = 0; i < len; ++i)
    {
        if (t[i] == s[pos])
            pos++;
        if (pos == strlen(s) - 1)
        {
            break;
        }
    }
    printf("%d\n", pos + 1);
    return 0;
}