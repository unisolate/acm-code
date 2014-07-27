#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        bool flag = false;
        long long t = 1;
        while (t <= n)
        {
            if (t == n)
            {
                flag = true;
                break;
            }
            t *= 2;
        }
        if (flag)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}