#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
typedef unsigned long long ll;
ll x, y, a, b;
ll c(ll v) {
    if (v < 6) return 0;
    a = v / 2 - 2;
    b = sqrt((long double)v);
    if (b % 2) return a + 1;
    else return a;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> x >> y;
        cout << c(y) - c(x - 1) << endl;
    }
    return 0;
}