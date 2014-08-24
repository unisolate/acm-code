#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long a[50005];

int main()
{
    int n;
    for (int i = 1; i <= 50000; i++)
        a[i] = i * (i + 1) / 2;
    while (~scanf("%d", &n))
    {
        if (n == 2)
        {
            printf("1 1\n1 2\n2 1\n");
            continue;
        }
        if (n == 3)
        {
            printf("0 2\n3 2 1\n2 1 3\n");
            continue;
        }
        if (a[n] % 2 == 1 && n % 2 == 1)
        {
            printf("1 %d\n", n);
            for (int i = n; i > 1; i--)
                printf("%d ", i);
            printf("1\n");
            for (int i = n - 1; i >= 1; i--)
                printf("%d ", i);
            printf("%d\n", n);
        }
        else if (a[n] % 2 == 1 && n % 2 == 0)
        {
            printf("1 %d\n", n - 1);
            for (int i = n; i > 1; i--)
                printf("%d ", i);
            printf("1\n");
            for (int i = n - 1; i >= 1; i--)
                printf("%d ", i);
            printf("%d\n", n);
        }
        else if (a[n] % 2 == 0 && n % 2 == 0)
        {
            printf("0 %d\n", n);
            for (int i = n; i > 1; i--)
                printf("%d ", i);
            printf("1\n");
            for (int i = n - 1; i >= 1; i--)
                printf("%d ", i);
            printf("%d\n", n);
        }
        else
        {
            printf("0 %d\n", n);
            for (int i = n; i > 1; i--)
                printf("%d ", i);
            printf("1\n");
            for (int i = n - 1; i >= 1; i--)
                printf("%d ", i);
            printf("%d\n", n);
        }
    }
    return 0;
}