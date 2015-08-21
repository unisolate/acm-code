#include <cstdio>
#include <cstring>
#define MX 100010
using namespace std;
char a[MX], b[MX];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s%s", a, b);
        int x = strlen(a), y = strlen(b), j = 1;
        bool f = (a[0] == b[0]);
        for (int i = 1; i < x; ++i, ++j) {
            while (j < y && a[i] != b[j]) {
                ++j;
            }
            if (j >= y) {
                f = false;
                break;
            }
        }
        while (j < y) {
            if (b[j] == b[j - 1]) {
                f = false;
                break;
            }
            ++j;
        }
        puts(f ? "Yes" : "No");
    }
    return 0;
}