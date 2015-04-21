#include <cstdio>
using namespace std;
int main() {
    for (int i = 1; i < 10; ++i)
        printf("%d\n", i & (-i));
    int t, o;
    long long x, y;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &o);
        if (o == 1) {
            scanf("%lld", &x);
        } else {
            scanf("%lld%lld", &x, &y);
        }
    }
    return 0;
}

/*

1
2 1 2
3 2 3 1 3 2 3
4 3 4 2 4 3 4 1 4 3 4 2 4 3 4

*/