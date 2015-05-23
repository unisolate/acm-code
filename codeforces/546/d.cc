#include <cstdio>
#define MX 5000005
using namespace std;
int tag[MX], p[MX];
long long sum[MX];
void prime() {
    int cnt = 0;
    for (int i = 2; i < MX; ++i) {
        if (!tag[i])  p[cnt++] = i;
        for (int j = 0; j < cnt && p[j] * i < MX; j++) {
            tag[i * p[j]] = 1;
            if (i % p[j] == 0)
                break;
        }

    }
}
int main() {
    prime();
    for (int i = 1; i < MX; ++i) {
        int x = i;
        for (int j = 0; j < MX; ++j) {
            if (x == 1)
                break;
            if (tag[x] == 0) {
                ++sum[i];
                break;
            }
            while (x % p[j] == 0) {
                x /= p[j];
                ++sum[i];
            }
        }
    }
    for (int i = 2; i < MX; ++i) {
        sum[i] += sum[i - 1];
    }
    int t, a, b;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        scanf("%d%d", &a, &b);
        printf("%lld\n", sum[a] - sum[b]);
    }
    return 0;
}