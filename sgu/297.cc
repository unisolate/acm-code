/*
12.05.14 16:08  15 ms   62 kb
*/
#include <iostream>
using namespace std;
int main()
{
    int n, m, t, s = 0;
    cin >> n >> m;
    while (m--)
    {
        cin >> t;
        s += t;
    }
    cout << s % n << endl;
    return 0;
}