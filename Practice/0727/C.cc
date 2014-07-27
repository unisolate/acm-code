#include <bits/stdc++.h>
using namespace std;
char q[111];
int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas)
    {
        scanf("%s%d%d", q, &n, &m);
        int len = strlen(q);
        while (n * m < len)
        {
            if (n >= m)
                m += n;
            else n += m;
        }
        
        printf("Case #%d: %s\n", cas,);
    }
    return 0;
}