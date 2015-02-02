#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll c(ll p, int n) {
    ll r = 1;
    for (int i = 0; i < n; ++i)
        r *= 10;
    if (p % r == r - 1)
        return p;
    else return (p / r - 1) * r + r - 1;
}
int main() {
    ll p, d, a;
    cin >> p >> d;
    a = p;
    int n = 1;
    while (1) {
        ll t = c(p, n);
        if (p - t > d)
            break;
        else a = t, ++n;
    }
    cout << a;
    return 0;
}