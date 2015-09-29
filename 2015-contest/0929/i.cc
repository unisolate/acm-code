#include <cstdio>
#include <cstring>
#define MX 256
using namespace std;
char s[MX];
int v[MX];
int len;
bool C(int k) {
    for (int i = 0; i < len; ++i) {
        v[i] = s[i] - '0';
    }
    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j < len - k + 1; ++j) {
            if (v[j] == i) {
                continue;
            }
            int d = i - v[j];
            if (d < 0) {
                d += 10;
            }
            for (int l = 0; l < k; ++l) {
                v[j + l] = (v[j + l] + d) % 10;
            }
        }
        bool f = true;
        for (int j = 0; j < len; ++j) {
            if (v[j] != i) {
                f = false;
                break;
            }
        }
        if (f) {
            return true;
        }
    }
    return false;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        len = strlen(s);
        for (int i = len; i >= 1; --i) {
            if (C(i)) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}