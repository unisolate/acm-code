#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#define PIE 3.1415926
using namespace std;
int main()
{
    char temp[10];
    int aa, bb, cas = 1;
    while (scanf("%d%s%d", &aa, temp, &bb) && aa + bb)
    {
        double a = aa, b = bb, angle = atan(b / a);
        double k = 200 / (2 * angle * pow((a / 2) * (a / 2) + (b / 2) * (b / 2), 0.5) + a);
        cout << "Case " << cas++ << ": ";
        printf("%.2lf", a * k);
        cout << " ";
        printf("%.2lf\n", b * k);

    }
    return 0;
}