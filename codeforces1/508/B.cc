#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[102400];
int main() {
    scanf("%s", s);
    int n = strlen(s);
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        if ((s[i] - '0') % 2 == 0 && s[i] < s[n - 1]) {
            swap(s[i], s[n - 1]);
            flag = true;
            break;
        }
    }
    if (!flag) {
        for (int i = n - 2; i >= 0; --i) {
            if ((s[i] - '0') % 2 == 0) {
                swap(s[i], s[n - 1]);
                flag = true;
                break;
            }
        }
    }
    if (flag)
        printf("%s", s);
    else puts("-1");
    return 0;
}