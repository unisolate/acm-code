#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
struct node {
    int l, r, pos;
    ll minn, lazy;
    bool flag;
} tree[800010];
struct node2 {
    int l, r;
    ll cost;
} arr[200010];
int T, t, n, m;
ll d[200010], INF = 1e18;
void build(int l, int r, int tr) {
    tree[tr].l = l;
    tree[tr].r = r;
    tree[tr].flag = 1;
    tree[tr].lazy = 0;
    if (l == r) {
        tree[tr].minn = d[l];
        tree[tr].pos = l;
        return;
    }
    int mi = (l + r) / 2;
    build(l, mi, tr * 2);
    build(mi + 1, r, tr * 2 + 1);
    tree[tr].minn = min(tree[tr * 2].minn, tree[tr * 2 + 1].minn);
    tree[tr].pos = l;
}

void up(int tr) {
    if (tree[tr * 2].flag && tree[tr * 2 + 1].flag) {
        if (tree[tr * 2].minn <= tree[tr * 2 + 1].minn) {
            tree[tr].minn = tree[tr * 2].minn;
            tree[tr].pos = tree[tr * 2].pos;
        } else {
            tree[tr].minn = tree[tr * 2 + 1].minn;
            tree[tr].pos = tree[tr * 2 + 1].pos;
        }

    } else if (tree[tr * 2].flag) {
        tree[tr].minn = tree[tr * 2].minn;
        tree[tr].pos = tree[tr * 2].pos;
    } else if (tree[tr * 2 + 1].flag) {
        tree[tr].minn = tree[tr * 2 + 1].minn;
        tree[tr].pos = tree[tr * 2 + 1].pos;
    } else
        tree[tr].flag = 0;
}
void down(int tr) {
    if (tree[tr].lazy > 0) {
        if (tree[tr * 2].lazy == 0)
            tree[tr * 2].lazy = tree[tr].lazy;
        else
            tree[tr * 2].lazy = min(tree[tr * 2].lazy, tree[tr].lazy);
        tree[tr * 2].minn = min(tree[tr * 2].minn, tree[tr * 2].lazy);

        if (tree[tr * 2 + 1].lazy == 0)
            tree[tr * 2 + 1].lazy = tree[tr].lazy;
        else
            tree[tr * 2 + 1].lazy = min(tree[tr * 2 + 1].lazy, tree[tr].lazy);
        tree[tr * 2 + 1].minn = min(tree[tr * 2 + 1].minn, tree[tr * 2 + 1].lazy);

        tree[tr].lazy = 0;
    }
}
void update1(int l, int r, int tr, ll num) {
    if (tree[tr].l == l && tree[tr].r == r) {
        if (tree[tr].lazy == 0)
            tree[tr].lazy = num;
        else
            tree[tr].lazy = min(tree[tr].lazy, num);
        tree[tr].minn = min(tree[tr].minn, tree[tr].lazy);
        return;
    }
    down(tr);
    int mi = (tree[tr].l + tree[tr].r) / 2;
    if (r <= mi)
        update1(l, r, tr * 2, num);
    else if (l > mi)
        update1(l, r, tr * 2 + 1, num);
    else {
        update1(l, mi, tr * 2, num);
        update1(mi + 1, r, tr * 2 + 1, num);
    }
    up(tr);
}
void update2(int id, int tr) {
    if (tree[tr].l == tree[tr].r) {
        tree[tr].flag = 0;
        return;
    }
    down(tr);
    int mi = (tree[tr].l + tree[tr].r) / 2;
    if (id <= mi)
        update2(id, tr * 2);
    else
        update2(id, tr * 2 + 1);
    up(tr);
}
int main() {
    int i, j, k, pos, l, r;
    ll minn;
    scanf("%d", &T);
    for (t = 1; t <= T; t++) {
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
            scanf("%d", &arr[i].l);
        for (i = 1; i <= n; i++)
            scanf("%d", &arr[i].r);
        for (i = 1; i <= n; i++)
            scanf("%I64d", &arr[i].cost);
        d[1] = 0;
        for (i = 2; i <= n; i++)
            d[i] = INF;
        build(1, n, 1);
        while (tree[1].flag) {
            minn = tree[1].minn;
            pos = tree[1].pos;
            if (minn == INF)
                break;
            d[pos] = minn;
            update2(pos, 1);
            l = max(1, pos - arr[pos].r);
            r = pos - arr[pos].l;
            if (l <= r)
                update1(l, r, 1, minn + arr[pos].cost);

            l = pos + arr[pos].l;
            r = min(n, pos + arr[pos].r);
            if (l <= r)
                update1(l, r, 1, minn + arr[pos].cost);
        }
        for (i = 1; i <= n; i++)
            if (d[i] == INF)
                d[i] = -1;
        printf("%I64d", d[1]);
        for (i = 2; i <= n; i++)
            printf(" %I64d", d[i]);
        printf("\n");
    }
}