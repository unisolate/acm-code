#include <cstdio>
#include <cstring>
using namespace std;
char s[222222];
int main()
{
    scanf("%s", s);
    int l = strlen(s);
    for (int i = 0; i < l; ++i)
    {
        if (s[i] != s[l - i - 1])
            s[l - i - 1] = s[i];
    }
    printf("%s\n", s);
    return 0;
}