#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int n, x[111];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &x[i]);
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (x[i] > x[j])
                {
                    flag = true;
                    x[i] -= x[j];
                }
                else if (x[i] < x[j])
                {
                    flag = true;
                    x[j] -= x[i];
                }
    }
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += x[i];
    printf("%d\n", sum);
    return 0;
}