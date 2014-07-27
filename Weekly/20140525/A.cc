#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int n, p, sum = 0;
    scanf("%d", &n);
    int e = 0, o = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &p);
        sum += p;
        if (p % 2)
            o++;
        else e++;
    }
    if (sum % 2)
        printf("%d\n", o);
    else printf("%d\n", e);
    return 0;
}