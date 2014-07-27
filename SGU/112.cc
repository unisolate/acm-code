#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long long m, n;
    cin >> m >> n;
    cout << pow(m, n) - pow(n, m) << endl;
    return 0;
}