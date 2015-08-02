#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int mx = 1005;
char chr[mx][mx];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int dp[mx][mx], nx, ny, tl, m, n;
bool vis[mx][mx];
struct Node {
    int x, y;
} node[mx * mx], n1[mx * mx];
void dfs(int x, int y) {
    if (chr[x][y] == '1') {
        node[tl].x = x;
        node[tl++].y = y;
        return;
    }
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx > 0 && nx <= n && ny > 0 && ny <= n && !vis[nx][ny]) {
            vis[nx][ny] = true;
            dfs(nx, ny);
        }
    }
}
void solve() {
    memset(vis, 0, sizeof(vis));
    int dis = 1000005;
    int ed = 0;
    bool jud;
    for (int i = 0; i < tl; i++) {
        dis = min(dis, m + n - (node[i].x + node[i].y));
    }
    for (int i = 0; i < tl; i++) {
        if (m + n - (node[i].x + node[i].y) == dis) {
            n1[ed].x = node[i].x;
            n1[ed++].y = node[i].y;
        }
    }
    for (int i = 0; i < ed; i++) {
        node[i].x = n1[i].x;
        node[i].y = n1[i].y;
        vis[node[i].x][node[i].y] = 1;
    }
    tl = ed;
    printf("1");
    while (dis) {
        jud = false;
        for (int i = 0; i < tl; i++) {
            for (int j = 0; j < 2; j++) {
                nx = node[i].x + dx[j];
                ny = node[i].y + dy[j];
                if (!vis[nx][ny] && nx >= 1 && nx <= n && ny >= 1 && ny <= m
                        && chr[nx][ny] == '0')
                    jud = true;
            }
            if (jud)break;
        }
        if (jud)printf("0");
        else printf("1");
        ed = 0;
        for (int i = 0; i < tl; i++) {
            for (int j = 0; j < 2; j++) {
                nx = node[i].x + dx[j];
                ny = node[i].y + dy[j];
                if (!vis[nx][ny] && nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                    vis[nx][ny] = 1;
                    if (jud && chr[nx][ny] == '0') {
                        n1[ed].x = nx;
                        n1[ed++].y = ny;
                    }
                    if (!jud && chr[nx][ny] == '1') {
                        n1[ed].x = nx;
                        n1[ed++].y = ny;
                    }
                }
            }
        }
        for (int i = 0; i < ed; i++) {
            node[i].x = n1[i].x;
            node[i].y = n1[i].y;
        }
        tl = ed;
        dis--;
    }
    puts("");
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%s", chr[i] + 1);
        memset(dp, -1, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        tl = 0;
        dfs(1, 1);
        vis[1][1] = 1;
        if (vis[n][m])printf("%c\n", chr[n][m]);
        else
            solve();
    }
    return 0;
}