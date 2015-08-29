#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#define MX 1024
using namespace std;
int a;
char b[MX];
double f() {
    if (b[0] == 'A') {
        if (strlen(b) == 1)
            return 4.0;
        else
            return 3.7;
    } else if (b[0] == 'B') {
        if (strlen(b) == 1)
            return 3.0;
        if (b[1] == '+')
            return 3.3;
        else
            return 2.7;
    } else if (b[0] == 'C') {
        if (strlen(b) == 1)
            return 2.0;
        if (b[1] == '+')
            return 2.3;
        else
            return 1.7;
    } else if (b[0] == 'D') {
        if (strlen(b) == 1)
            return 1.3;
        else
            return 1.0;
    } else
        return 0.0;
}
int main() {
    int n;
    while (~scanf("%d", &n)) {
        double x = 0.0, y = 0.0;
        bool t = false;
        for (int i = 0; i < n; ++i) {
            scanf("%d%s", &a, b);
            if (b[0] != 'P' && b[0] != 'N') {
                t = true;
                x += a * f();
                y += a;
            }
        }
        if (t)
            printf("%.2lf\n", round(x * 100 / y) / 100);
        else
            puts("0.00");
    }
    return 0;
}