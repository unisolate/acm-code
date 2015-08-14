#include <cstdio>
using namespace std;
struct Node {
    int p;
    int v[26];
} p[555555];
char c[555555];
int n, m, v, h;
void dfs() {

}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &p[i].p);
    }
    scanf("%s", c);
    for (int i = 1; i <= n; ++i) {
        p[i].v[c[i + 1]] = 1;
    }
    dfs();
    while (m--) {
        scanf("%d%d", &v, &h);
    }
    return 0;
}