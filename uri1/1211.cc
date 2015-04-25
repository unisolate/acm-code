#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s[111111];
int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        int a = 0, p = 0;
        for (int i = 0; i < n; ++i)
            cin >> s[i];
        sort(s, s + n);
        int l = s[0].size();
        for (int i = 1; i < n; ++i)
        {
            if (s[i][0] != s[p][0])
                p = i;
            else
            {
                int t = 0;
                for (int j = p; j < i; ++j)
                {
                    int k = 0;
                    while (k < l && s[i][k] == s[j][k])
                        ++k;
                    t = max(t, k);
                }
                a += t;
            }
        }
        printf("%d\n", a);
    }
    return 0;
}

/*
3 
12345 
12367 
12367
3
12345
12367
12368
*/