#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, _min, _max;
    while (~scanf("%d", &n))
    {
        long long s = (long long)n * (n + 1) / 2, p = (long long)n * (n - 1) / 2;
        if (s % 2)
            _min = 1;
        else _min = 0;
        if (p % 2)
            _max = n - 1;
        else _max = n;
        printf("%d %d\n", _min, _max);
        for (int i = n; i > 1; --i)
            printf("%d ", i);
        printf("1\n");
        for (int i = n - 1; i >= 1; --i)
            printf("%d ", i);
        printf("%d\n", n);
    }
    return 0;
}