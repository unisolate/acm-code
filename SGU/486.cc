/*
14.05.14 18:24	15 ms	54 kb
*/
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    char x[10], y[10];
    int bull = 0, cow = 0;
    scanf("%s%s", x, y);
    for (int i = 0; i < 4; ++i)
    {
        if (x[i] == y[i])
            bull++;
    }
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (j == i)
                continue;
            if (x[i] == y[j])
                cow++;
        }
    }
    printf("%d %d\n", bull, cow);
    return 0;
}