#include <cstdio>
#include <map>
#define MX 100001
using namespace std;
typedef long long ll;
ll p[MX];
char s[64];
map<int, int> e;
ll add(ll x, ll y) {
    ll r = 0, k = 1, l = 0, q = 0;
    while (x || y || l) {
        q = x % 10 + y % 10 + l;
        l = q / 4;
        r += k * (q % 4);
        k *= 10;
        x /= 10, y /= 10;
    }
    return r;
}
int main() {
    int x = 1, y = 2;
    while (y < MX) {
        e[y] = x;
        ++x;
        y *= 2;
    }

    p[1] = 1;
    ll m = 0;
    for (int i = 2; i < MX; ++i) {
        if (e[i]) {
            m = 1;
            if (e[i] % 2) {
                for (int j = 0; j <= e[i] / 2; ++j)
                    m *= 10;
            } else {
                m *= 2;
                for (int j = 0; j < e[i] / 2; ++j)
                    m *= 10;
            }
            ++m;
        }
        if (i % 2) {
            p[i] = add(p[i - 1], m);
            m = add(m, 10);
        } else {
            p[i] = p[i / 2] * 10;
        }
    }

    int n;
    while (scanf("%d", &n) && n) {
        int k = 0;
        ll t = p[n];
        while (t) {
            s[k++] = 'A' + (t % 10);
            t /= 10;
        }
        for (int i = k - 1; i >= 0; --i)
            putchar(s[i]);
        puts("");
    }
    return 0;
}