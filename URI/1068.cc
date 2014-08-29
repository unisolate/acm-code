#include <bits/stdc++.h>
using namespace std;
char p[1111];
int main()
{
    while (~scanf("%s", p))
    {
        int l = strlen(p), x = 0;
        bool f = true;
        for (int i = 0; i < l; ++i)
            if (p[i] == '(')
                ++x;
            else if (p[i] == ')')
            {
                if (x) --x;
                else f = false;
            }
        if (x) f = false;
        if (f) puts("correct");
        else puts("incorrect");
    }
    return 0;
}