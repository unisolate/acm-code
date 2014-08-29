#include <bits/stdc++.h>
using namespace std;
char p[1111];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", p);
        int l = strlen(p), a = 0, x = 0;
        for (int i = 0; i < l; ++i)
            if (p[i] == '<')
                ++x;
            else if (p[i] == '>' && x)
                --x, ++a;
        printf("%d\n", a);
    }
    return 0;
}