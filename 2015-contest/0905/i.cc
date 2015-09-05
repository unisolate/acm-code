#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#define MX 333
using namespace std;
string s, t, d[MX][MX];
int a, b, c[MX];
struct P {
    int num[MX];
} p[MX];
double V, O, E, U, I[MX], N;
int cmp(P x, P y) {
    return x.num[a + 2] < y.num[a + 2];
}
int main() {
    freopen("ideal.in", "r", stdin);
    freopen("ideal.out", "w", stdout);
    while (getline(cin, s)) {
        stringstream ss(s);
        // cout << s << endl;
        ss >> t;
        // cout << t << endl;
        if (t[0] == 'T' && t[1] == 'e' && t[2] == 'a' && t[3] == 'm')
            break;
    }
    stringstream sss(s);
    while (sss >> t) {
        // cout << t << endl;
        if (t[0] == '=')
            break;
        ++a;
    }
    a -= 1;
    getline(cin, s);
    while (getline(cin, s)) {
        stringstream ss(s);
        while (ss >> d[b][c[b]]) {
            ++c[b];
        }
        for (int i = c[b] - a - 3; i < c[b] - 3; ++i) {
            if (d[b][i][0] == '+') {
                p[b].num[i - c[b] + a + 3] = 1;
            } else if (d[b][i][0] == '-') {
                p[b].num[i - c[b] + a + 3] = -1;
            }
        }
        for (int i = 0; i < 3; ++i)
            p[b].num[a + i] = atoi(d[b][c[b] - 3 + i].c_str());
        ++b;
    }
    sort(p, p + b, cmp);
    // for (int i = 0; i < b; ++i) {
    //     for (int j = 0; j < a + 3; ++j) {
    //         printf("%d ", p[i].num[j]);
    //     }
    //     puts("");
    // }
    for (int i = 0; i < b; ++i) {
        if (p[i].num[a] == 0) {
            V += 1 / (double)b;
        }
        if (p[i].num[a] == a) {
            O += 1 / (double)b;
        }
        if (i > 0 && p[i - 1].num[a] - p[i].num[a] > 1) {
            E += (p[i - 1].num[a] - p[i].num[a] - 1) * (1 / (double)a);
        }
    }
    for (int i = 0; i < a; ++i) {
        bool f = false;
        for (int j = 0; j < b; ++j) {
            if (p[j].num[i] > 0)
                f = true;
        }
        if (!f)
            U += 1 / (double)a;

        f = false;
        int pre = 0;
        for (int j = b - 1; j >= 0; --j) {
            if (f == false && p[j].num[i] > 0) {
                f = true;
                pre = p[j].num[a + 2];
            }
            if (p[j].num[i] <= 0 && f && p[j].num[a + 2] < pre) {
                I[i] += 1 / (double)b;
            }
        }
    }
    // printf("%d %d\n", a, b);
    // for (int i = 0; i < b; ++i) {
    //     printf("%d\n", c[i]);
    // }
    printf("Vainness = %.3lf\n", V);
    printf("Oversimplification = %.3lf\n", O);
    printf("Evenness = %.3lf\n", E);
    printf("Unsolvability = %.3lf\n", U);
    N = 1.03 * V + 3.141 * O + 2.171 * E + 1.414 * U;
    double k = 0.0;
    for (int i = 0; i < a; ++i) {
        k += I[i];
        printf("Instability %d = %.3lf\n", i + 1, I[i]);
    }
    N += k / a;
    printf("Negidealness = %.3lf\n", N);
    return 0;
}