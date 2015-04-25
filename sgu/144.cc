/*
08.05.14 19:16	15 ms	58 kb
*/
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int x, y;
    double z, p;
    cin >> x >> y >> z;
    int m = (y - x) * 60;
    p = z / m + ((m - z) / m) * (z / m);
    printf("%.7lf\n", p);
    return 0;
}