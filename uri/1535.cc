#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
using namespace std;
typedef long long ll;
char s[99];
ll x, y;
int main() {
    while (gets(s)) {
        x = y = 0;
        int l = strlen(s), p = 0;
        bool f = false;
        for (int i = 0; i < l; ++i)
            if (s[i] == ' ') {
                f = true;
                p = i;
                break;
            }
        if (f) {
            int k = 1;
            for (int i = p - 1; i > 0; --i) {
                x += (s[i] - '0') * k;
                k *= 10;
            }
            if (s[0] == '-')
                x = -x;
            else x += (s[0] - '0') * k;

            k = 1;
            for (int i = l - 1; i > p + 1; --i) {
                y += (s[i] - '0') * k;
                k *= 10;
            }
            if (s[p + 1] == '-')
                y = -y;
            else y += (s[p + 1] - '0') * k;

            while (!(x % 2 == 0 && x % 4)) ++x;
            while (!(y % 2 == 0 && y % 4)) --y;
            printf("%lld\n", (y - x) / 4 + 1);
        } else {
            x = atoi(s);
            if (x % 2) {
                printf("%lld %lld\n", (x + 1) / 2, (x - 1) / 2);
            } else {
                if (x % 4) {
                    puts("Bachelor Number.");
                } else {
                    printf("%lld %lld\n", (x / 2 + 2) / 2, (x / 2 - 2) / 2);
                }
            }
        }
    }
    return 0;
}