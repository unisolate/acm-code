#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, a[111];
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    bool flag = true;
    int l = 1;
    while (flag)
    {
        flag = false;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] > 0)
            {
                flag = true;
                l = i;
                a[i] -= m;
            }
        }
    }
    printf("%d\n", l);
    return 0;
}