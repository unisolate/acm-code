#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int z[10], s[10], m[10], p[10];
int main() {
    char l[99];
    while (gets(l)) {
        for (int i = 0; i < 10; ++i)
            z[i] = s[i] = m[i] = p[i] = 0;
        for (int i = 0; i < 14; ++i) {
            int v = l[i * 2] - '0';
            if (l[i * 2 + 1] == 'z')
                ++z[v];
            else if (l[i * 2 + 1] == 's')
                ++s[v];
            else if (l[i * 2 + 1] == 'm')
                ++m[v];
            else if (l[i * 2 + 1] == 'p')
                ++p[v];
        }
        bool f1 = false, f2 = true;
        int t = 0;
        for (int i = 0; i < 10; ++i) {
            if (z[i] == 2)
                ++t;
            if (s[i] == 2)
                ++t;
            if (m[i] == 2)
                ++t;
            if (p[i] == 2)
                ++t;
        }
        if (t == 7)
            f1 = true;
        if (t != 1)
            f2 = false;
        for (int i = 1; i <= 7; ++i)
            if (!z[i])
                f2 = false;
        int c = 0;
        for (int i = 1; i <= 9; ++i)
            if (s[i])
                ++c;
        if (!c)
            f2 = false;
        c = 0;
        for (int i = 1; i <= 9; ++i)
            if (m[i])
                ++c;
        if (!c)
            f2 = false;
        c = 0;
        for (int i = 1; i <= 9; ++i)
            if (p[i])
                ++c;
        if (!c)
            f2 = false;
        if (f1)
            puts("Seven Pairs");
        else if (f2)
            puts("Thirteen Orphans");
        else puts("Neither!");
    }
    return 0;
}