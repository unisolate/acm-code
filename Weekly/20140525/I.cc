#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int n, k;
    bool flag[1111];
    memset(flag, true, sizeof(flag));
    scanf("%d%d", &n, &k);
    int a[k];
    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &a[i]);
        flag[a[i]] = false;
    }
    int pos = 0;
    for (int i = 0; i < k; ++i)
    {
        printf("%d", a[i]);
        int c = 1;
        while (c < n)
        {
            pos++;
            if (flag[pos])
            {
                printf(" %d", pos);
                c++;
            }
        }
        printf("\n");
    }
    return 0;
}