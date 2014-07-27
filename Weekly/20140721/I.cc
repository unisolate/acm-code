#include <bits/stdc++.h>
using namespace std;
int h[111][111];
int main()
{
    int t;
    char name[1000];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s%d%d", name, &x, &y);
        for (int i = 0; i < x; ++i)
            for (int j = 0; j < y; ++j)
                scanf("%d", &h[i][j]);
        printf("%s: %d\n", name,);
    }
    return 0;
}