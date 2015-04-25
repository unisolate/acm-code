/*
30.04.14 18:10  15 ms   66 kb
*/
#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    char p[m + 1][111];
    for (int i = 1; i < m; ++i)
        cin >> p[i];
    cin >> p[0];
    cout << p[n % m] << endl;
    return 0;
}