/*
ID: unisola1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    char a[10], b[10];
    int x = 1, y = 1;
    cin >> a >> b;
    for (int i = 0; i < strlen(a); ++i)
        x *= a[i] - 'A' + 1;
    for (int i = 0; i < strlen(b); ++i)
        y *= b[i] - 'A' + 1;
    if (x % 47 == y % 47)
        cout << "GO" << endl; else
        cout << "STAY" << endl;
    return 0;
}