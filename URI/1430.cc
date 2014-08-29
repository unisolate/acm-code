#include <bits/stdc++.h>
using namespace std;
double m[256];
char s[222];
int main()
{
    m['W'] = 1, m['H'] = 1.0 / 2, m['Q'] = 1.0 / 4, m['E'] = 1.0 / 8, m['S'] = 1.0 / 16, m['T'] = 1.0 / 32, m['X'] = 1.0 / 64;
    while (scanf("%s", s) && s[0] != '*')
    {
        int l = strlen(s), a = 0;
        double x = 0;
        for (int i = 1; i < l; ++i)
            if (s[i] != '/')
                x += m[s[i]];
            else
            {
                if (x == 1)++a;
                x = 0;
            }
        printf("%d\n", a);
    }
    return 0;
}