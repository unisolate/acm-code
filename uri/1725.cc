#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MX 1024
using namespace std;
char s[MX][MX], t[MX];
int n, p[MX][MX];
void dfs(int x, int y, int d) {
    for (int i = 0; i < d; ++i)
        for (int j = 0; j < d; ++j)
            if (p[x + i][y + j] != p[x][y]) {
                putchar('Q');
                dfs(x, y, d / 2);
                dfs(x, y + d / 2, d / 2);
                dfs(x + d / 2, y, d / 2);
                dfs(x + d / 2, y + d / 2, d / 2);
                return;
            }
    if (p[x][y])
        putchar('B');
    else putchar('W');
}
int main() {
    for (int i = 0; i < 6; ++i)
        scanf("%s", t);
    n = atoi(t);
    for (int i = 0; i < 5; ++i)
        scanf("%s", t);
    for (int i = 0; i < n; ++i)
        scanf("%s", s[i]);
    scanf("%s", t);
    int l = n / 8;
    if (n % 8) ++l;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < l; ++j) {
            if (s[i][j * 5 + 3] == '1') {
                p[i][j * 8] = 1;
            } else if (s[i][j * 5 + 3] == '2') {
                p[i][j * 8 + 1] = 1;
            } else if (s[i][j * 5 + 3] == '3') {
                p[i][j * 8 + 1] = p[i][j * 8] = 1;
            } else if (s[i][j * 5 + 3] == '4') {
                p[i][j * 8 + 2] = 1;
            } else if (s[i][j * 5 + 3] == '5') {
                p[i][j * 8 + 2] = p[i][j * 8] = 1;
            } else if (s[i][j * 5 + 3] == '6') {
                p[i][j * 8 + 2] = p[i][j * 8 + 1] = 1;
            } else if (s[i][j * 5 + 3] == '7') {
                p[i][j * 8 + 2] = p[i][j * 8 + 1] = p[i][j * 8] = 1;
            } else if (s[i][j * 5 + 3] == '8') {
                p[i][j * 8 + 3] = 1;
            } else if (s[i][j * 5 + 3] == '9') {
                p[i][j * 8 + 3] = p[i][j * 8] = 1;
            } else if (s[i][j * 5 + 3] == 'a') {
                p[i][j * 8 + 3] = p[i][j * 8 + 1] = 1;
            } else if (s[i][j * 5 + 3] == 'b') {
                p[i][j * 8 + 3] = p[i][j * 8 + 1] = p[i][j * 8] = 1;
            } else if (s[i][j * 5 + 3] == 'c') {
                p[i][j * 8 + 3] = p[i][j * 8 + 2] = 1;
            } else if (s[i][j * 5 + 3] == 'd') {
                p[i][j * 8 + 3] = p[i][j * 8 + 2] = p[i][j * 8] = 1;
            } else if (s[i][j * 5 + 3] == 'e') {
                p[i][j * 8 + 3] = p[i][j * 8 + 2] = p[i][j * 8 + 1] = 1;
            } else if (s[i][j * 5 + 3] == 'f') {
                p[i][j * 8 + 3] = p[i][j * 8 + 2] = p[i][j * 8 + 1] = p[i][j * 8] = 1;
            }

            if (s[i][j * 5 + 2] == '1') {
                p[i][j * 8 + 4] = 1;
            } else if (s[i][j * 5 + 2] == '2') {
                p[i][j * 8 + 5] = 1;
            } else if (s[i][j * 5 + 2] == '3') {
                p[i][j * 8 + 5] = p[i][j * 8 + 4] = 1;
            } else if (s[i][j * 5 + 2] == '4') {
                p[i][j * 8 + 6] = 1;
            } else if (s[i][j * 5 + 2] == '5') {
                p[i][j * 8 + 6] = p[i][j * 8 + 4] = 1;
            } else if (s[i][j * 5 + 2] == '6') {
                p[i][j * 8 + 6] = p[i][j * 8 + 5] = 1;
            } else if (s[i][j * 5 + 2] == '7') {
                p[i][j * 8 + 6] = p[i][j * 8 + 5] = p[i][j * 8 + 4] = 1;
            } else if (s[i][j * 5 + 2] == '8') {
                p[i][j * 8 + 7] = 1;
            } else if (s[i][j * 5 + 2] == '9') {
                p[i][j * 8 + 7] = p[i][j * 8 + 4] = 1;
            } else if (s[i][j * 5 + 2] == 'a') {
                p[i][j * 8 + 7] = p[i][j * 8 + 5] = 1;
            } else if (s[i][j * 5 + 2] == 'b') {
                p[i][j * 8 + 7] = p[i][j * 8 + 5] = p[i][j * 8 + 4] = 1;
            } else if (s[i][j * 5 + 2] == 'c') {
                p[i][j * 8 + 7] = p[i][j * 8 + 6] = 1;
            } else if (s[i][j * 5 + 2] == 'd') {
                p[i][j * 8 + 7] = p[i][j * 8 + 6] = p[i][j * 8 + 4] = 1;
            } else if (s[i][j * 5 + 2] == 'e') {
                p[i][j * 8 + 7] = p[i][j * 8 + 6] = p[i][j * 8 + 5] = 1;
            } else if (s[i][j * 5 + 2] == 'f') {
                p[i][j * 8 + 7] = p[i][j * 8 + 6] = p[i][j * 8 + 5] = p[i][j * 8 + 4] = 1;
            }
        }
    }
    printf("%d\n", n);
    dfs(0, 0, n);
    puts("");
    return 0;
}
/*
#define quadtree_width 16
#define quadtree_height 16
static char quadtree_bits[] = {
0xf0,0xf0,
0xf0,0xf0,
0xf0,0xf0,
0xf0,0xf0,
0x0f,0x0f,
0x0f,0x0f,
0x0f,0x0f,
0x0f,0x0f,
0xf0,0xf0,
0xf0,0xf0,
0xf0,0xf0,
0xf0,0xf0,
0x0f,0x0f,
0x0f,0x0f,
0x0f,0x0f,
0x0f,0x0f,
};
*/