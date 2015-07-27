#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int a[3], b[3];
    for (int i = 0; i < 3; ++i)
        scanf("%d%d", a + i, b + i);
    if (a[0] > b[0])swap(a[0], b[0]);
    if (a[1] > b[1])swap(a[1], b[1]);
    if (a[2] > b[2])swap(a[2], b[2]);
    bool f = false;
    if ((a[0] >= a[1] + a[2] && b[0] >= max(b[1], b[2]))
            || (a[0] >= max(a[1], a[2]) && b[0] >= b[1] + b[2])
            || (a[0] >= a[1] + b[2] && b[0] >= b[1] + a[2])
            || (a[0] >= max(a[1], b[2]) && b[0] >= b[1] + a[2])
            || (a[0] >= b[1] + b[2] && b[0] >= max(a[1], a[2]))
            || (a[0] >= max(b[1], b[2]) && b[0] >= a[1] + a[2])
            || (a[0] >= b[1] + a[2] && b[0] >= a[1] + b[2])
            || (a[0] >= max(b[1], a[2]) && b[0] >= a[1] + b[2]))
        f = true;
    if (f)puts("YES");
    else puts("NO");
    return 0;
}