#include <cstdio>
#define MX 128
using namespace std;
int a[MX], b[MX], k[MX][MX];
int main() {
    int n, m, p, q;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &b[i]);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &p, &q);
        k[p][q] = 1;
        k[q][p] = 1;
    }
    
    return 0;
}