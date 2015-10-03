#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#define MAXN 10010
using namespace std;
bool p[MAXN];
void findprime()
{
    for (int i = 0; i < MAXN; i++)
        p[i] = true;
    p[0] = false;
    p[1] = false;
    for (int i = 2; i < MAXN; i++)
        if (p[i])
            for (int j = i * i; j < MAXN; j += i)
                p[j] = false;
}
int main()
{
    int n;
    findprime();
    while (scanf("%d", &n) && n)
    {
        int ans = 0;
        for (int i = 2; i <= n; ++i)
        {
            if (p[i])
            {
                int s = 0, j;
                for (j = i; j <= n && s <= n; ++j)
                {
                    if (p[j])
                        s += j;
                    if (s == n)
                    {
                        ans++;
                        break;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}