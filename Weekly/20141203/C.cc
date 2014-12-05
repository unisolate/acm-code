#include <cstdio>
#include <cmath>
using namespace std;
int a[1111];
int main()
{
    int t, n;
    double p;
    scanf("%d", &t);
    while (t--)
    {
        int s = 0;
        scanf("%d%lf", &n, &p);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]), s += a[i];
        
        printf("%d\n", (int)(s * p + 1 - 0.0001));
    }
    return 0;
}