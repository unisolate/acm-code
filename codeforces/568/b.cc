#include <cstdio>
#include <algorithm>
#include <map>
#define MX 100010
using namespace std;
map<int, int> m;
int p[MX];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", p + i);
        ++m[p[i]];
    }
    for (int i = 0; i < n - 1; ++i)
        printf("%d ", p[i]);
    printf("%d\n", p[n - 1]);
    return 0;
}
// struct P {
//     int i;
//     int v;
// } p[MX];
// int cmp1(P a, P b) {
//     return a.v < b.v;
// }
// int cmp2(P a, P b) {
//     return a.i < b.i;
// }
// int main() {
//     int n;
//     scanf("%d", &n);
//     for (int i = 0; i < n; ++i) {
//         scanf("%d", &p[i].v);
//         p[i].i = i;
//     }
//     sort(p, p + n, cmp1);
//     for (int i = 0; i < n; ++i) {
//         p[i].v = i + 1;
//     }
//     sort(p, p + n, cmp2);
//     for (int i = 0; i < n - 1; ++i) {
//         printf("%d ", p[i].v);
//     }
//     printf("%d\n", p[n - 1].v);
//     return 0;
// }