#include <cstdio>
using namespace std;
int n, m, a, b, x, y, u, v, p;
int main() {
    scanf("%d%d%d%d", &n, &m, &a, &b);
    x = (a - 1) % m, y = (b - 1) % m;
    u = (a - 1) / m, v = (b - 1) / m;
    if (m == 1 || u == v)
        p = 1;
    else if (x == 0) {
        if (b == n || y == m - 1)
            p = 1;
        else p = 2;
    } else {
        if (b == n || y == m - 1)
            p = 2;
        else {
            if (v - u == 1)
                p = 2;
            else if (x - y == 1)
                p = 2;
            else p = 3;
        }
    }
    printf("%d", p);
    return 0;
}