#include <cstdio>
#include <queue>
#define MX 333
using namespace std;
int p, m, n, x;
char s[9];
struct C{

}c[MX];
queue<C> q;
int main() {
    while (scanf("%d%d%d", &p, &m, &n) && p + m + n) {
    	while(!q.empty()) q.pop();
        for (int i = 0; i < n; ++i) {
            scanf("%d%s", &x, s);
            q.push();
        }
    }
    return 0;
}