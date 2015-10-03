#include <iostream>
#include <cstdio>
#include <cstring>
#define MX 1111
using namespace std;
int x[MX], w[MX];
bool f[MX];
int main()
{
    int n, k, p, sum = 0, pos = 0, flag = 0;
    char op[5];
    scanf("%d%d", &n, &k);
    while (k--)
    {
        scanf("%d", &p);
        for (int i = 0; i < 2 * p; ++i)
            scanf("%d", &x[i]);
        scanf("%s", op);
        if (op[0] == '=')
        {
            for (int i = 0; i < 2 * p; ++i)
                f[x[i]] = true;
        }
        else if (op[0] == '<')
        {
            sum++;
            for (int i = 0; i < p; ++i)
                w[x[i]]--;
            for (int i = p; i < 2 * p; ++i)
                w[x[i]]++;
        }
        else if (op[0] == '>')
        {
            sum++;
            for (int i = 0; i < p; ++i)
                w[x[i]]++;
            for (int i = p; i < 2 * p; ++i)
                w[x[i]]--;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (f[i])
            continue;
        if (w[i] == sum || w[i] == -sum)
            flag++, pos = i;
    }
    if (flag == 1)
        printf("%d\n", pos);
    else printf("0\n");
    return 0;
}