#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#define ls l,m,n<<1
#define rs m+1,r,n<<1|1
#define MX 200020
using namespace std;
typedef long long ll;
int N, L, R, u[MX], v[MX];
bool vis[MX];
ll V, c[MX], mi[MX << 2];
void B(int l = 1, int r = N, int n = 1) {
    if (l == r) {
        mi[n] = 0;
        return;
    }
    int m = (l + r) >> 1;
    B(ls), B(rs);
}
void U(int l = 1, int r = N, int n = 1) {

}
ll Q(int l = 1, int r = N, int n = 1) {

}
void W(int p) {
    if (vis[p])
        return;

    for (int i = u[p]; i <= v[p]; ++i) {
        if (p + i > N && p - i < 1)
            break;
        if (p + i <= N) {
            W(p + i);
        }
        if (p - i >= 1) {
            W(p - i);
        }
    }
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i)
            scanf("%d", u + i);
        for (int i = 1; i <= N; ++i)
            scanf("%d", v + i);
        for (int i = 1; i <= N; ++i) {
            scanf("%lld", c + i);
            vis[i] = false;
        }
        B();
        W(1);
        for (int i = 1; i <= N; ++i) {
            if (vis[i]) {
                printf("%d", Q());
            } else {
                printf("-1");
            }
            printf("%c", (i == N) ? '\n' : ' ');
        }
    }
    return 0;
}