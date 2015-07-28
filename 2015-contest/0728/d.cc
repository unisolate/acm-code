#include <cstdio>
#include <cstring>
#define MX 64
using namespace std;
int n;
char s[MX][MX], p[MX][MX];
void dr(int x, int y) {
    while (x < n && y < n) {
        if (s[x][y] == 'R') {
            p[x][y] = 'R';
            ++x, ++y;
        } else if (s[x][y] == 'G') {
            if (p[x][y] == 'G') return;
            else if (p[x][y] == 'B') p[x][y] = 'G';
            else p[x][y] = 'R';
            ++x, ++y;
        } else {
            return;
        }
    }
}
void db(int x, int y) {
    while (x < n && y >= 0) {
        if (s[x][y] == 'B') {
            p[x][y] = 'B';
            ++x, --y;
        } else if (s[x][y] == 'G') {
            if (p[x][y] == 'G') return;
            else if (p[x][y] == 'R') p[x][y] = 'G';
            else p[x][y] = 'B';
            ++x, --y;
        } else {
            return;
        }
    }
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(p, 0, sizeof(p));
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%s", s[i]);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s[i][j] == 'R' && p[i][j] != 'R') {
                    p[i][j] = 'R';
                    dr(i + 1, j + 1);
                    ++ans;
                } else if (s[i][j] == 'B' && p[i][j] != 'B') {
                    p[i][j] = 'B';
                    db(i + 1, j - 1);
                    ++ans;
                } else if (s[i][j] == 'G' && p[i][j] != 'G') {
                    if (p[i][j] == 'R') {
                        p[i][j] = 'G';
                        db(i + 1, j - 1);
                        ++ans;
                    } else if (p[i][j] == 'B') {
                        p[i][j] = 'G';
                        dr(i + 1, j + 1);
                        ++ans;
                    } else {
                        p[i][j] = 'G';
                        db(i + 1, j - 1);
                        dr(i + 1, j + 1);
                        ans += 2;
                    }
                }
                // for(int i=0;i<n;++i){
                // 	for(int j=0;j<n;++j){
                // 		printf("%c",p[i][j]==0?' ':p[i][j]);
                // 	}
                // 	printf("\n");
                // }
                // printf("\n");
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}