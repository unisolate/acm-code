// st
int p[MX], d[MX][20];
void init(int n) {
    for (int i = 0; i < n; ++i)
        d[i][0] = p[i];
    for (int j = 1; (1 << j) <= n; ++j)
        for (int i = 0; i + (1 << j) - 1 < n; ++i)
            d[i][j] = max(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
}
int rmq(int x, int y) {
    if (x > y)
        return 0;
    int k = 0;
    while ((1 << (k + 1)) <= y - x + 1)
        ++k;
    return max(d[x][k], d[y - (1 << k) + 1][k]);
}

// bit
int p[MX], d[MX];
void init(int n) {
    for (int i = 1; i < n; ++i) {
        d[i] = p[i];
        for (int j = 1; j < (i & -i); j <<= 1)
            d[i] = max(d[i], d[i - j]);
    }
}
int rmq(int x, int y) {
    if (x > y) return 0;
    int ans = p[y];
    while (1) {
        ans = max(ans, p[y]);
        if (x == y) break;
        for (y -= 1; y - x >= (y & -y); y -= (y & -y))
            ans = max(ans, d[y]);
    }
    return ans;
}

#include <cstdio>
#include <algorithm>
#define MX 1000001
using namespace std;
typedef long long ll;
ll p[MX], d[MX][20];
void init(int n) {
    for (int i = 0; i < n; ++i)
        d[i][0] = p[i];
    for (int j = 1; (1 << j) <= n; ++j)
        for (int i = 0; i + (1 << j) - 1 < n; ++i)
            d[i][j] = max(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
}
int rmq(int x, int y) {
    if (x > y)
        return 0;
    int k = 0;
    while ((1 << (k + 1)) <= y - x + 1)
        ++k;
    return max(d[x][k], d[y - (1 << k) + 1][k]);
}
int main() {
    int t, n, k, s;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &k, &s);
        p[0] = s;
        for (int i = 1; i < n; ++i)
            p[i] = (1LL * p[i - 1] * 1103515245 + 12345) % (2147483648LL);
        init(n);
        ll ans = 0;
        for (int i = 0; i <= n - k; ++i)
            ans += rmq(i, i + k - 1);
        printf("%lld\n", ans);
    }
    return 0;
}

//给出一个非降序列，求某区间内数字最大的出现次数。
//st算法比树状数组更快一点，但是树状数组需要的空间小。

//st算法
int p[MX], l[MX], r[MX], val[MX], cnt[MX], num[MX], d[MX][20];
void init(int n) {
    for (int i = 0; i < n; ++i)
        d[i][0] = cnt[i];
    for (int j = 1; (1 << j) <= n; ++j)
        for (int i = 0; i + (1 << j) - 1 < n; ++i)
            d[i][j] = max(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
}
int rmq(int x, int y) {
    if (x > y)
        return 0;
    int k = 0;
    while ((1 << (k + 1)) <= y - x + 1)
        ++k;
    return max(d[x][k], d[y - (1 << k) + 1][k]);
}
int main() {
    int n, q;
    while (~scanf("%d", &n) && n) {
        scanf("%d", &q);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &p[i]);
        p[n + 1] = -MX;
        int k = 0;
        cnt[k] = 1, val[k] = p[1], l[1] = 1;
        for (int i = 2; i <= n + 1; ++i) {
            if (p[i] == p[i - 1])
                ++cnt[k], l[i] = l[i - 1], num[i] = k;
            else {
                for (int j = l[i - 1]; j < i; ++j)
                    r[j] = i - 1;
                ++k, num[i] = k, l[i] = i, cnt[k] = 1, val[k] = p[i];
            }
        }
        // for (int i = 1; i <= n; ++i)
        //     printf("#%d %d %d\n", l[i], r[i], num[i]);
        // for (int i = 0; i < k; ++i)
        //     printf("##%d %d\n", cnt[i], val[i]);
        int x, y, ans;
        init(k);
        while (q--) {
            scanf("%d%d", &x, &y);
            if (num[x] == num[y])
                ans = y - x + 1;
            else ans = max(max(r[x] - x + 1, y - l[y] + 1), rmq(num[x] + 1, num[y] - 1));
            printf("%d\n", ans);
        }
    }
    return 0;
}

//树状数组
#include <bits/stdc++.h>
#define MX 100010
using namespace std;
int p[MX], l[MX], r[MX], val[MX], cnt[MX], num[MX], idx[MX];
void init(int n) {
    for (int i = 1; i < n; ++i) {
        idx[i] = cnt[i];
        for (int j = 1; j < (i & -i); j <<= 1)
            idx[i] = max(idx[i], idx[i - j]);
    }
}
int query(int x, int y) {
    if (x > y)return 0;
    int ans = cnt[y];
    while (1) {
        ans = max(ans, cnt[y]);
        if (x == y) break;
        for (y -= 1; y - x >= (y & -y); y -= (y & -y))
            ans = max(ans, idx[y]);
    }
    return ans;
}
int main() {
    int n, q;
    while (~scanf("%d", &n) && n) {
        scanf("%d", &q);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &p[i]);
        p[n + 1] = -MX;
        int k = 1;
        cnt[k] = 1, val[k] = p[1], l[1] = 1, num[1] = k;
        for (int i = 2; i <= n + 1; ++i) {
            if (p[i] == p[i - 1])
                ++cnt[k], l[i] = l[i - 1], num[i] = k;
            else {
                for (int j = l[i - 1]; j < i; ++j)
                    r[j] = i - 1;
                ++k, num[i] = k, l[i] = i, cnt[k] = 1, val[k] = p[i];
            }
        }
        int x, y, ans;
        init(k);
        while (q--) {
            scanf("%d%d", &x, &y);
            if (num[x] == num[y])
                ans = y - x + 1;
            else ans = max(max(r[x] - x + 1, y - l[y] + 1), query(num[x] + 1, num[y] - 1));
            printf("%d\n", ans);
        }
    }
    return 0;
}
