#include <cstdio>
#include <algorithm>
using namespace std;
struct P {
    int a, c;
    char s[11];
} p[3001];
int cmp(P x, P y)
{
    return x.a < y.a;
}
int b[3001];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d", p[i].s, &p[i].a);
    }
    sort(p, p + n, cmp);
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        int h = p[i].a;
        if (i - h < 0) {
            flag = false;
            break;
        }
        for (int j = i - 1; j >= i - h; --j)
            b[j + 1] = b[j];
        b[i - h] = i;
    }
    for (int i = 0; i < n; ++i)
        p[b[i]].c = i + 1;
    if (flag) {
        for (int i = 0; i < n; ++i) {
            printf("%s %d\n", p[i].s, p[i].c);
        }
    }
    else puts("-1");
    return 0;
}