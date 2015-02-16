#include <cstdio>
#include <cstring>
using namespace std;
char s[99];
int main() {
    scanf("%s", s);
    if (s[0] - '0' > 4 && s[0] != '9')
        putchar('0' + '9' - s[0]);
    else putchar(s[0]);
    for (int i = 1; i < strlen(s); ++i) {
        if (s[i] - '0' > 4)
            putchar('0' + '9' - s[i]);
        else putchar(s[i]);
    }
    return 0;
}