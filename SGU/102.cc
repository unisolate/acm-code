/*
27.04.14 17:03  15 ms   58 kb
*/
#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    return (b ? gcd(b, a % b) : a);
}
int main()
{
    int n, m = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        if (gcd(i, n) == 1)
            m++;
    cout << m << endl;
    return 0;
}