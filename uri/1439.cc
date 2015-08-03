#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
struct C {
    int x;
    char s[2];
    bool operator < (C c) const {
        if (x == c.x) return s[0] < c.s[0];
        return x < c.x;
    }
};
queue<C> q;
vector<C> v[10];
int main() {
    C card;
    bool dir;
    int cur, p, m, n;
    // freopen("bora.in", "r", stdin);
    while (scanf("%d%d%d", &p, &m, &n) && p + m + n) {
        for (int i = 0; i < p; ++i) {
            v[i].clear();
            for (int j = 0; j < m; ++j) {
                scanf("%d%s", &card.x, card.s);
                v[i].push_back(card);
            }
        }
        while (!q.empty()) q.pop();
        for (int i = 0; i < n - p * m; ++i) {
            scanf("%d%s", &card.x, card.s);
            q.push(card);
        }
        dir = true;
        cur = 0;
        card = q.front();
        q.pop();
        switch (card.x) {
        case 12:
            dir = !dir;
            break;
        case 7:
            v[cur].push_back(q.front());
            q.pop();
        case 1:
            v[cur].push_back(q.front());
            q.pop();
        case 11:
            cur = (cur + (dir ? 1 : p - 1)) % p;
            break;
        }
        while (1) {
            // printf("#%d\n", cur);
            int dis = -1;
            for (int i = 0; i < v[cur].size(); ++i) {
                if (v[cur][i].x == card.x || v[cur][i].s[0] == card.s[0]) {
                    if (dis == -1 || v[cur][dis] < v[cur][i]) {
                        // card = v[cur][i];
                        dis = i;
                    }
                }
            }
            if (dis != -1) {
                // printf("##%d %s\n", v[cur][dis].x, v[cur][dis].s);
                card = v[cur][dis];
                v[cur].erase(v[cur].begin() + dis, v[cur].begin() + dis + 1);
                if (v[cur].size() == 0) {
                    printf("%d\n", cur + 1);
                    break;
                }
                switch (card.x) {
                case 12:
                    dir = !dir;
                    break;
                case 7:
                    v[(cur + (dir ? 1 : p - 1)) % p].push_back(q.front());
                    q.pop();
                case 1:
                    v[(cur + (dir ? 1 : p - 1)) % p].push_back(q.front());
                    q.pop();
                case 11:
                    cur = (cur + (dir ? 1 : p - 1)) % p;
                    break;
                }
                cur = (cur + (dir ? 1 : p - 1)) % p;
            } else {
                v[cur].push_back(q.front());
                q.pop();
                if (v[cur].back().x == card.x || v[cur].back().s[0] == card.s[0]) {
                    // printf("###%d %s\n", v[cur].back().x, v[cur].back().s);
                    card = v[cur].back();
                    v[cur].erase(v[cur].end() - 1);
                    switch (card.x) {
                    case 12:
                        dir = !dir;
                        break;
                    case 7:
                        v[(cur + (dir ? 1 : p - 1)) % p].push_back(q.front());
                        q.pop();
                    case 1:
                        v[(cur + (dir ? 1 : p - 1)) % p].push_back(q.front());
                        q.pop();
                    case 11:
                        cur = (cur + (dir ? 1 : p - 1)) % p;
                        break;
                    }
                }
                cur = (cur + (dir ? 1 : p - 1)) % p;
            }
        }
    }
    return 0;
}