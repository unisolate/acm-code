#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define MX 128
using namespace std;
int r, c, n, t, x[MX], y[MX], l;
int p[MX][MX];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<pair<pair<int, int>, int> > v;
void crack(int a, int b) {
    v.push_back(make_pair(make_pair(a, b), 0));
    v.push_back(make_pair(make_pair(a, b), 1));
    v.push_back(make_pair(make_pair(a, b), 2));
    v.push_back(make_pair(make_pair(a, b), 3));
}
int main() {
    while (~scanf("%d%d%d%d", &r, &c, &n, &t)) {
        memset(p, 0, sizeof(p));
        v.clear();
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &x[i], &y[i], &l);
            p[x[i]][y[i]] = l;
        }
        scanf("%d%d", &x[n], &y[n]);
        crack(x[n], y[n]);
        for (int i = 0; i < t; ++i) {
            l = v.size();
            for (int j = 0; j < l; ++j) {
                if (v[j].second != -1) {
                    // printf("%d %d %d\n", v[j].first.first, v[j].first.first, v[j].second);
                    v[j].first.first += dx[v[j].second];
                    v[j].first.second += dy[v[j].second];
                    if (v[j].first.first > 0 && v[j].first.first <= r && v[j].first.second > 0
                            && v[j].first.second <= c) {
                        if (p[v[j].first.first][v[j].first.second] > 0) {
                            ++p[v[j].first.first][v[j].first.second];
                            v[j].second = -1;
                        }
                    } else v[j].second = -1;
                }
            }
            for (int j = 0; j < n; ++j) {
                if (p[x[j]][y[j]] > 4) {
                    crack(x[j], y[j]);
                    p[x[j]][y[j]] = -i - 1;
                }
            }
            // if (v.empty())
            //     break;
        }
        for (int i = 0; i < n; ++i) {
            if (p[x[i]][y[i]] < 0) {
                printf("0 %d\n", -p[x[i]][y[i]]);
            } else {
                printf("1 %d\n", p[x[i]][y[i]]);
            }
        }
    }
    return 0;
}