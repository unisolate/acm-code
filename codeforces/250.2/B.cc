#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
using namespace std;
int m[111111], ans[111111];
int main()
{
    memset(m, 0, sizeof(m));
    memset(ans, 0, sizeof(ans));
    int s, l, sum = 0;
    scanf("%d%d", &s, &l);
    for (int i = 1; i <= l; ++i)
        m[(i & -i)]++;
    int b = 1, a = 0;
    while (b <= s)
        b *= 2;
    b /= 2;
    while (b > 0 && a < s)
    {
        while (m[b] > 0 && a < s)
        {
            m[b]--;
            sum++;
            ans[b]++;
            a += b;
        }
        if (a == s)
            break;
        else if (a > s)
        {
            a -= b;
            sum--;
            ans[b]--;
        }
        b /= 2;
    }
    if (a == s)
    {
        printf("%d\n", sum);
        int k = 0;
        for (int i = 1; i <= l && k < sum; ++i)
        {
            if (ans[(i & -i)] > 0)
            {
                if (k == 0)
                    printf("%d", i);
                else printf(" %d", i);
                ans[(i & -i)]--;
                k++;
            }
        }
        putchar(10);
    }
    else printf("-1\n");
    return 0;
}