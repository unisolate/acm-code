#include <cstdio>
using namespace std;
int main()
{
    int n, t, a = 0, b = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &t);
        if (t == 100)
            a++;
        else b++;
    }
    if ((a % 2) || (b % 2 && a == 0))
        printf("NO\n");
    else printf("YES\n");
    return 0;
}