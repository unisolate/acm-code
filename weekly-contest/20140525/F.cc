#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    char s[1111];
    int k[256];
    memset(k, 0, sizeof(k));
    scanf("%s", s);
    for (int i = 0; i < strlen(s); ++i)
        k[s[i]]++;
    int ans = 0;
    for (int i = 'a'; i <= 'z'; ++i)
        if (k[i] % 2)
            ans++;
    if (ans == 0 || ans % 2)
        printf("First\n");
    else printf("Second\n");
    return 0;
}