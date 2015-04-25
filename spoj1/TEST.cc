#include <cstdio>
int main()
{
    int n;
    bool flag = true;
    while (~scanf("%d", &n))
    {
        if (n == 42)flag = false;
        if (flag)printf("%d\n", n);
    }
    return 0;
}