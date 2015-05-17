#include <cstdio>
using namespace std;
int l[9] = {5, 6, 7, 8, 9, 8, 7, 6, 5};
int dx[6] = {0, 0, 1, 1, -1, -1};
int dy[6] = { -1, 1, 0, 1, 0, 1};
char s[9][9], ss[9];
inline bool ok(int i, int j) {
    return i >= 0 && i < 9 && j >= 0 && j < l[i];
}
int main() {
    int t, cas = 0;
    scanf("%d", &t);
    while (t--) {
        bool b = false, w = false;
        int cw = 0, cb = 0;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < l[i]; ++j) {
                scanf("%s", ss);
                s[i][j] = ss[0];
                if (ss[0] == 'W')++cw;
                if (ss[0] == 'B')++cb;
            }
        }
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < l[i]; ++j) {
                if (s[i][j] == 'W') {
                    for (int k = 0; k < 6; ++k) {
                        if (ok(i + dx[k], j + dy[k]) && s[i + dx[k]][j + dy[k]] == 'B') {
                        	
                        }
                    }
                }
            }
        }
        if (!w) {

        }
        printf("Case %d: ", ++cas);
        if (b == false && w == false)
            puts("Draw");
        else if (w)
            puts("White");
        else puts("Black");
    }
    return 0;
}