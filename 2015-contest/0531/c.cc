#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    int t, cas = 0;
    char s[999];
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        int k = strlen(s);
        if (s[k - 4] == 'd' && s[k - 3] == 'e' && s[k - 2] == 's' && s[k - 1] == 'u') {
            s[k - 4] = 'n';
            s[k - 3] = 'a';
            s[k - 2] = 'n';
            s[k - 1] = 'o';
            s[k] = 'd';
            s[k + 1] = 'e';
            s[k + 2] = 's';
            s[k + 3] = 'u';
            s[k + 4] = '\0';
        } else {
            s[k] = 'n';
            s[k + 1] = 'a';
            s[k + 2] = 'n';
            s[k + 3] = 'o';
            s[k + 4] = 'd';
            s[k + 5] = 'e';
            s[k + 6] = 's';
            s[k + 7] = 'u';
            s[k + 8] = '\0';
        }
        printf("Case #%d: %s\n", ++cas, s);
    }
    return 0;
}