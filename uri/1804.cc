#include <iostream>
#include <cstdio>
using namespace std;
int c[102400], p[102400];
void U(int x, int v) {
    for (; x < 102400; x += (x & -x))c[x] += v;
}
int Q(int x) {
    int r = 0;
    for (; x > 0; x -= (x & -x))r += c[x];
    return r;
}
int main() {
    int n, a;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", p + i);
        U(i + 1, p[i]);
    }
    char op[9];
    while (~scanf("%s%d", op, &a)) {
        if (op[0] == 'a')U(a, -p[a - 1]);
        else printf("%d\n", Q(a - 1));
    }
    return 0;
}