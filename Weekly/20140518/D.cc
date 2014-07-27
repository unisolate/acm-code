#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#define MX 16000010
using namespace std;
char s[MX];
int ha[MX], a[256];
int main()
{
    int n, nc;
    while (~scanf("%d%d", &n, &nc))
    {
        int k = 0, sum = 0, ans = 0;
        memset(a, 0, sizeof(a));
        memset(ha, 0, sizeof(ha));
        scanf("%s", s);
        int len = strlen(s);
        for (int i = 0; i < len; ++i)
        {
            if (!a[s[i]])
                a[s[i]] = k++;
            if (k == nc)
                break;
        }
        len = len - n + 1;
        for (int i = 0; i < len; ++i)
        {
            sum = 0;
            for (int j = 0; j < n; ++j)
                sum = sum * nc + a[s[i + j]];
            if (!ha[sum])
                ha[sum] = 1, ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}