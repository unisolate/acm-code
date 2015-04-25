/*
09.05.14 19:36	171 ms	62 kb
*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n <= 8)
        cout << 0 << endl;
    else if (n == 9)
        cout << 8 << endl;
    else
    {
        cout << 72;
        for (int i = 11; i <= n; ++i)
            cout << 0;
        cout << endl;
    }
    return 0;
}