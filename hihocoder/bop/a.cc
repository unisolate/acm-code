#include <cstdio>
#include <cstdlib>
using namespace std;
char m1[99], m2[99], d1[99], d2[99];
int y1, y2;
bool is(int y) {
    return (y % 400 == 0 || (y % 4 == 0 && y % 100));
}
int main() {
    int t, cas = 0;
    scanf("%d", &t);
    while (t--) {
        int ans = 0;
        scanf("%s%s%d", m1, d1, &y1);
        scanf("%s%s%d", m2, d2, &y2);
        bool f1 = true, f2 = true;
        if (is(y1) && (m1[0] == 'F' || (m1[0] == 'J' && m1[1] == 'a'))) {
            ++ans;
            f1 = false;
        }
        for (int i = y1 + 1; i < y2; ++i)
            if (is(i))
                ++ans;
        if (is(y2) && (!((m2[0] == 'F' || (m2[0] == 'J' && m2[1] == 'a')))
                       || (m2[0] == 'F' && atoi(d2) == 29))) {
            ++ans;
            f2 = false;
        }
        if (y1 == y2 && !(f1 && f2)) {
            --ans;
        }
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}