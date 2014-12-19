#include <cstdio>
#include <cstring>
// #include <ctype>
using namespace std;
char s[22];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", s);
        for (int i = 0; i < strlen(s); ++i)
        {
            // s[i] = toupper(s[i]);
            if (s[i] > 'Z') s[i] -= 'a' - 'A';
            if (s[i] >= 'A' && s[i] <= 'C')
                s[i] = 2;
            else if (s[i] >= 'D' && s[i] <= 'F')
                s[i] = 3;
            else if (s[i] >= 'G' && s[i] <= 'I')
                s[i] = 4;
            else if (s[i] >= 'J' && s[i] <= 'L')
                s[i] = 5;
            else if (s[i] >= 'M' && s[i] <= 'O')
                s[i] = 6;
            else if (s[i] >= 'P' && s[i] <= 'S')
                s[i] = 7;
            else if (s[i] >= 'T' && s[i] <= 'V')
                s[i] = 8;
            else if (s[i] >= 'W' && s[i] <= 'Z')
                s[i] = 9;
        }
        bool flag = true;
        for (int i = 0; i < strlen(s); ++i)
            if (s[i] != s[strlen(s) - i - 1])
                flag = false;
        if (flag)
            puts("YES");
        else puts("NO");
    }
    return 0;
}