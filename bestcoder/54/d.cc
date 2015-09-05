#include <cstdio>
#define MX 1000005
using namespace std;
int phi[MX];
void euler() {
    int i, j;
    for (i = 0; i < MX; i++)
        phi[i] = 0;
    for (i = 2; i < MX; i++) {
        if (!phi[i])
            for (j = i; j < MX; j += i) {
                if (!phi[j])
                    phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
    }
}
int main() {
    euler();
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", phi[n + 1]);
    }
    return 0;
}