#include <bits/stdc++.h>
#define eps 0.000001
using namespace std;
int main()
{
    double a, b, c, d, e, f;
    scanf("%lf%lf", &a, &b);
    bool flag = false;
    for (int i = 1; i < (int)a; ++i)
    {
        double k = i * i;
        c = sqrt(a * a - k);
        if (c - (double)((int)c) < eps)
        {
            if ((int)c != i)
            {
                d = (double)i * b / a;
                e = c * b / a;
                if (d - (double)((int)d) < eps && e - (double)((int)e) < eps && (int)c != (int)d)
                {
                    f = i;
                    flag = true;
                    break;
                }
            }
        }
    }
    if (flag)
    {
        puts("YES");
        printf("0 0\n%d %d\n%d %d\n", (int)f, (int)c, -(int)e, (int)d);
    }
    else puts("NO");
    return 0;
}