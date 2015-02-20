#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    char s1[100], s2[100], op;
    int num, ans = 0;
    while (scanf("%s", s1) && s1[0] != '#')
    {
        if (s1[0] == '0')
        {
            printf("%d\n", ans);
            ans = 0;
            continue;
        }
        scanf("%s %d %c", s2, &num, &op);
        if (op == 'F')
        {
            ans += num * 2;
        }
        else if (op == 'B')
        {
            int add = num / 2;
            if (num % 2)
                add++;
            ans += num + add;
        }
        else if (op == 'Y')
        {
            if (num < 500)
                ans += 500;
            else ans += num;
        }
    }
    return 0;
}