/*
30.04.14 17:51	15 ms	58 kb
*/
#include <iostream>
using namespace std;
int mid(int a, int b, int c)
{
    int t;
    if (a > b)
    {
        t = a; a = b; b = t;
    }
    if (b > c)
    {
        t = b; b = c; c = t;
    }
    if (a > b)
    {
        t = a; a = b; b = t;
    }
    return b;
}
int main()
{
    int a[9];
    for (int i = 0; i < 9; ++i)
        cin >> a[i];
    cout << mid(mid(a[0], a[1], a[2]), mid(a[3], a[4], a[5]), mid(a[6], a[7], a[8])) << endl;
    return 0;
}