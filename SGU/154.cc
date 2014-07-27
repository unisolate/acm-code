/*
06.05.14 17:54	15 ms	58 kb
*/
#include <iostream>
#define MX 400000015
#define R 80000003
using namespace std;
int zero(int i)
{
    int r = 0, b = 5;
    while (i >= b)
    {
        r += i / b;
        b *= 5;
    }
    return r;
}
int main()
{
    int k, i = 0;
    cin >> k;
    if (k == 0)
    {
        cout << 1 << endl;
        return 0;
    }
    int l = 1, r = R, p = (l + r) >> 1;
    while (l <= r)
    {
        int m = zero(p * 5);
        if (m == k)
        {
            cout << p * 5 << endl;
            return 0;
        }
        if (m < k)
        {
            l = p + 1;
        }
        else if (m > k)
        {
            r = p - 1;
        }
        p = (l + r) >> 1;
    }
    cout << "No solution" << endl;
    return 0;
}