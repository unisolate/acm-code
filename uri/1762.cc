#include <cstdio>
#include <map>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
map<string, double> m;
int main() {
    int t, n, a;
    double v, c;
    string s;
    scanf("%d", &t);
    while (t--) {
        m.clear();
        scanf("%d", &n);
        // getchar();
        for (int i = 0; i < n; ++i) {
            getchar();
            getline(cin, s);
            scanf("%lf", &v);
            m[s] = v;
            // cout<<s<<v<<endl;
        }
        scanf("%lf", &c);
        // getchar();
        double ans = 0.0;
        while (getchar(), getline(cin, s)) {
            scanf("%d", &a);
            // cout<<s<<a<<endl;
            if (s == "-" && a == 0)
                break;
            if (m.count(s)) {
                ans += m[s] * a;
            } else {
                cout << "NAO LISTADO: " << s << endl;
            }
        }
        printf("Peso total: %.2lf kg\nNumero de trenos: %d\n\n", ans,
               (int)ceil(ans / c));
    }
    return 0;
}