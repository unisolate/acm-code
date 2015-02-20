#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    int t, n, m;
    scanf("%d", &t);
    while (t--)
    {
        int ma = 0, head = 0;
        scanf("%d%d", &n, &m);
        int p[n];
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &p[i]);
            if (p[i] > ma)
                ma = p[i];
        }
        int tim = 0, k = n;
        while (k)
        {
            if (p[head] == ma)
            {
                tim++;
                p[head] = -1;
                if (head == m)
                {
                    printf("%d\n", tim);
                    break;
                }
                head++;
                if (head >= n)
                    head = 0;
                k--;
                ma = 0;
                for (int i = 0; i < n; ++i)
                {
                    if (p[i] > ma)
                        ma = p[i];
                }
            }
            else
            {
                head++;
                if (head >= n)
                    head = 0;
            }
        }
    }
    return 0;
}