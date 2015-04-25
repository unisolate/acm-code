/*
01.05.14 12:30  15 ms   62 kb
输入一串字符，其中带有<UP>、</UP>、<DOWN>、</DOWN>标记，
标记包裹的字符相应的输出大写或小写。
唯一麻烦一点的就是标签重叠的处理。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    char p[1111];
    int flag[222], x = 0;
    flag[0] = 0;
    cin >> p;
    for (int i = 0; i < strlen(p); ++i)
    {
        if (p[i] == '<')
        {
            if (p[++i] == '/')
                flag[x--] = 0;
            else if (p[i] == 'U')
                flag[++x] = 1;
            else flag[++x] = -1;
            while (p[i] != '>')
                ++i;
            continue;
        }
        if (flag[x] == 0)
            cout << p[i];
        else if (flag[x] == 1)
            printf("%c", toupper(p[i]));
        else printf("%c", tolower(p[i]));
    }
    cout << endl;
    return 0;
}