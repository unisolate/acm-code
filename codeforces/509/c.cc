#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int p[333], y[333];
char a[333][999];
bool check(int i) {
    int x = 0;
    while (a[i][x] != 0)
        ++x;
    if (x > y[i - 1])
        return true;
    if (x < y[i - 1])
        return false;
    for (int t = x - 1; t >= 0; --t) {
        if (a[i][t] > a[i - 1][t])
            return true;
        else if (a[i][t] < a[i - 1][t])
            return false;
    }
    return false;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < p[i] / 9; ++j)
            a[i][j] = '9';
        int t = p[i] / 9;
        if (p[i] % 9)
            a[i][p[i] / 9] = '0' + p[i] % 9;
        else --t;
        while (!check(i)) {
            int u = 0;
            while (a[i][u] == '0' || a[i][u + 1] == '9')
                ++u;
            if (u == t)
            {
                for (int j = 0; j < p[i] / 9; ++j)
                    a[i][j] = '9';
                int v = p[i] / 9;
                if (p[i] % 9)
                    a[i][p[i] / 9] = '0' + p[i] % 9;
                else --v;
                // printf("#%d\n", v);
                ++t;
                a[i][t] = '1';
                --a[i][v];
                for (int j = v + 1; j < t; ++j)
                    a[i][j] = '0';

            } else {
                --a[i][u];
                ++a[i][u + 1];
            }
        }
        t = 0;
        while (a[i][t] != 0)
            ++t;
        y[i] = t;
        --t;
        while (t >= 0)
            putchar(a[i][t--]);
        putchar(10);
    }
    return 0;
}