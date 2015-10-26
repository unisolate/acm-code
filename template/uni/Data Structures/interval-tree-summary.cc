// 1. LA 3787
// 单点赋值，查询区间哈希值。
ll b, p, c[MX << 2], s[MX];
void up() {
    c[n] = (c[lc] * s[r - m] + c[rc]) % p;
}
ll Q(int l = 1, int r = N, int n = 1) {
    if (x <= l && r <= y) {
        return c[n] * s[y - r];
    }
    ... return ans % p;
}
void init() {
    s[0] = 1;
    for (int i = 1; i <= N; ++i)
        s[i] = (s[i - 1] * b) % p;
    memset(c, 0, sizeof(c));
}

// 2. 扫描线
struct seg {
    double l, r, p;
    int d;
    seg() {
    }
    seg(double _l, double _r, double _p, int _d) {
        l = _l, r = _r, p = _p, d = _d;
    }
} x[MX];
bool cmp(seg a, seg b) {
    return a.p < b.p;
}
double a, b, c, d, y[MX], sum[MX << 2];
int L, R, V, N, add[MX << 2];
void U(int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R) {
        add[n] += V;
        // printf("#%d %d %d\n", l, r, add[n]);
        sum[n] = add[n] ? (y[r + 1] - y[l]) : (l == r ? 0 : sum[lc] + sum[rc]);
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m)
        U(ls);
    if (m < R)
        U(rs);
    sum[n] = add[n] ? (y[r + 1] - y[l]) : (l == r ? 0 : sum[lc] + sum[rc]);
}
int main() {
    int n, k, cas = 0;
    while (scanf("%d", &n) && n) {
        n *= 2;
        for (int i = 1; i <= n; i += 2) {
            scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
            x[i] = seg(b, d, a, 1);
            x[i + 1] = seg(b, d, c, -1);
            y[i] = b;
            y[i + 1] = d;
        }
        sort(x + 1, x + n + 1, cmp);
        sort(y + 1, y + n + 1);
        N = unique(y + 1, y + n + 1) - y - 1;
        memset(sum, 0, sizeof(sum));
        memset(add, 0, sizeof(add));
        double ans = 0.0;
        for (int i = 1; i < n; ++i) {
            L = lower_bound(y + 1, y + N + 1, x[i].l) - y;
            R = lower_bound(y + 1, y + N + 1, x[i].r) - y - 1;
            V = x[i].d;
            if (L <= R)
                U();
            ans += sum[1] * (x[i + 1].p - x[i].p);
            // printf("%.2lf\n", sum[1]);
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n", ++cas, ans);
    }
    return 0;
}

// 3. HDU 3308
// 最长连续递增序列
int N, X, V, num[MX], mm[MX << 2], lm[MX << 2], rm[MX << 2];
void B(int l = 1, int r = N, int n = 1) {
    if (l == r) {
        scanf("%d", &num[l]);
        lm[n] = rm[n] = mm[n] = 1;
        return;
    }
    int m = (l + r) >> 1, k = r - l + 1;
    B(lson), B(rson);
    lm[n] = lm[lc];
    if (lm[lc] == k - (k >> 1) && num[m] < num[m + 1])
        lm[n] += lm[rc];
    rm[n] = rm[rc];
    if (rm[rc] == (k >> 1) && num[m] < num[m + 1])
        rm[n] += rm[lc];
    mm[n] = max(mm[lc], mm[rc]);
    if (num[m] < num[m + 1])
        mm[n] = max(mm[n], rm[lc] + lm[rc]);
}
void U(int l = 1, int r = N, int n = 1) {
    if (l == r) {
        num[l] = V;
        return;
    }
    int m = (l + r) >> 1, k = r - l + 1;
    if (X <= m)
        U(lson);
    else
        U(rson);
    lm[n] = lm[lc];
    if (lm[lc] == k - (k >> 1) && num[m] < num[m + 1])
        lm[n] += lm[rc];
    rm[n] = rm[rc];
    if (rm[rc] == (k >> 1) && num[m] < num[m + 1])
        rm[n] += rm[lc];
    mm[n] = max(mm[lc], mm[rc]);
    if (num[m] < num[m + 1])
        mm[n] = max(mm[n], rm[lc] + lm[rc]);
}
int QL(int L, int R, int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R)
        return lm[n];
    int m = (l + r) >> 1;
    if (L > m)
        return QL(L, R, rson);
    if (R <= m)
        return QL(L, R, lson);
    int ans = QL(L, m, lson), k = m - L + 1;
    if (ans == k && num[m] < num[m + 1])
        ans += QL(m + 1, R, rson);
    return ans;
}
int QR(int L, int R, int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R)
        return rm[n];
    int m = (l + r) >> 1;
    if (L > m)
        return QR(L, R, rson);
    if (R <= m)
        return QR(L, R, lson);
    int ans = QR(m + 1, R, rson), k = R - m;
    if (ans == k && num[m] < num[m + 1])
        ans += QR(L, m, lson);
    return ans;
}
int Q(int L, int R, int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R)
        return mm[n];
    int m = (l + r) >> 1;
    if (L > m)
        return Q(L, R, rson);
    if (R <= m)
        return Q(L, R, lson);
    int ans = max(Q(L, m, lson), Q(m + 1, R, rson));
    if (num[m] < num[m + 1])
        ans = max(ans, QR(L, m, lson) + QL(m + 1, R, rson));
    return ans;
}
int main() {
    int t, m, L, R;
    char o[9];
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &N, &m), B();
        while (m--) {
            scanf("%s", o);
            if (o[0] == 'Q') {
                scanf("%d%d", &L, &R), printf("%d\n", Q(L + 1, R + 1));
            } else {
                scanf("%d%d", &X, &V), ++X, U();
            }
        }
    }
    return 0;
}

// 4. POJ 3277
// 更新区间，只报留最大值
int v, N, L, R, x[MX], y[MX], h[MX], p[MX], s[MX << 2];
void B(int l = 1, int r = N, int n = 1) {
    if (l == r - 1)
        return;
    int m = (l + r) >> 1;
    B(lson), B(rson);
}
void U(int L, int R, int l = 1, int r = N, int n = 1) {
    if (p[l] == L && p[r] == R) {
        if (s[n] < h[v])
            s[n] = h[v];
        return;
    }
    int m = (l + r) >> 1;
    if (R <= p[m])
        U(L, R, lson);
    else if (L >= p[m])
        U(L, R, rson);
    else
        U(L, p[m], lson), U(p[m], R, rson);
}
ll Q(int l = 1, int r = N, int n = 1, int t = 0) {
    if (s[n] < t)
        s[n] = t;
    if (l == r - 1)
        return (ll)(p[r] - p[l]) * s[n];
    int m = (l + r) >> 1;
    return Q(lson, s[n]) + Q(rson, s[n]);
}
int main() {
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &x[i], &y[i], &h[i]);
        p[++N] = x[i], p[++N] = y[i];
    }
    sort(p + 1, p + N + 1);
    N = unique(p + 1, p + N + 1) - p - 1;
    B();
    for (v = 1; v <= m; ++v)
        U(x[v], y[v]);
    printf("%lld\n", Q());
    return 0;
}

// 5. HDU 3333
// 区间不重复数字和
struct S {
    int l, r, i;
} p[MX];
int x[MX], a[MX], f[MX];
ll c[MX], ans[MX];
int cmp(S a, S b) {
    return a.r < b.r;
}
void U(int x, int v) {
    for (; x < MX; x += (x & -x))
        c[x] += v;
}
ll Q(int x) {
    ll s = 0;
    for (; x > 0; x -= (x & -x))
        s += c[x];
    return s;
}
int B(int v, int u) {
    int l = 0, r = u - 1, m;
    while (l <= r) {
        m = (l + r) >> 1;
        if (x[m] == v)
            return m;
        if (x[m] < v)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
int main() {
    int t, n, q, l, r, cnt;
    scanf("%d", &t);
    while (t--) {
        memset(c, 0, sizeof(c));
        memset(f, 0, sizeof(f));
        scanf("%d", &n), cnt = n;
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]), x[i - 1] = a[i];
        sort(x, x + cnt);
        cnt = unique(x, x + cnt) - x;
        scanf("%d", &q);
        for (int i = 0; i < q; ++i)
            scanf("%d%d", &p[i].l, &p[i].r), p[i].i = i;
        sort(p, p + q, cmp);
        int k = 0, d;
        for (int i = 1; i <= n; ++i) {
            d = B(a[i], cnt);
            if (f[d])
                U(f[d], -a[i]);
            U(i, a[i]);
            f[d] = i;
            for (; k < q; ++k) {
                if (p[k].r == i)
                    ans[p[k].i] = Q(p[k].r) - Q(p[k].l - 1);
                else
                    break;
            }
        }
        for (int i = 0; i < q; ++i)
            printf("%I64d\n", ans[i]);
    }
    return 0;
}

// 6. POJ 2452
// 最大的 j-i 满足 a[i] 最小 a[j] 最大
int num[MX], ma[MX << 2], mi[MX << 2];
int L, R, N, ans;
inline void up(int n) {
    ma[n] = num[ma[lc]] > num[ma[rc]] ? ma[lc] : ma[rc];
    mi[n] = num[mi[lc]] < num[mi[rc]] ? mi[lc] : mi[rc];
}
void B(int l = 1, int r = N, int n = 1) {
    if (l == r) {
        scanf("%d", &num[l]);
        ma[n] = mi[n] = l;
        return;
    }
    int m = l + r >> 1;
    B(lson), B(rson), up(n);
}
int QA(int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R)
        return ma[n];
    int ans = 0, m = l + r >> 1, t;
    if (L <= m)
        t = QA(lson), ans = (num[ans] > num[t]) ? ans : t;
    if (m < R)
        t = QA(rson), ans = (num[ans] > num[t]) ? ans : t;
    return ans;
}
int QB(int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R)
        return mi[n];
    int ans = N + 1, m = l + r >> 1, t;
    if (L <= m)
        t = QB(lson), ans = (num[ans] < num[t]) ? ans : t;
    if (m < R)
        t = QB(rson), ans = (num[ans] < num[t]) ? ans : t;
    return ans;
}
int S(int l, int r) {
    if (l >= r)
        return -1;
    L = l, R = r;
    int ans = -1, a = QA(), b = QB();
    if (a > b)
        ans = max(a - b, max(S(l, b), S(a, r)));
    else
        ans = max(S(a + 1, b - 1), max(S(l, a), S(b, r)));
    return ans;
}
int main() {
    while (~scanf("%d", &N)) {
        B(), num[N + 1] = 111111;
        printf("%d\n", S(1, N));
    }
    return 0;
}

// 7. SPOJ GSS3
// 区间最大子序列和
int num, sum[MX << 2], mm[MX << 2], lm[MX << 2], rm[MX << 2];
int L, R, N, x, v;
inline void up(int n) {
    sum[n] = sum[lc] + sum[rc];
    lm[n] = max(lm[lc], sum[lc] + lm[rc]);
    rm[n] = max(rm[rc], sum[rc] + rm[lc]);
    mm[n] = max(rm[lc] + lm[rc], max(mm[lc], mm[rc]));
}
void B(int l = 1, int r = N, int n = 1) {
    if (l == r) {
        scanf("%d", &sum[n]);
        mm[n] = lm[n] = rm[n] = sum[n];
        return;
    }
    int m = l + r >> 1;
    B(lson), B(rson), up(n);
}
void U(int l = 1, int r = N, int n = 1) {
    if (l == r) {
        mm[n] = lm[n] = rm[n] = sum[n] = R;
        return;
    }
    int m = l + r >> 1;
    if (L <= m)
        U(lson);
    else
        U(rson);
    up(n);
}
int QL(int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R)
        return lm[n];
    int m = l + r >> 1, ans;
    if (L > m)
        return QL(rson);
    if (R <= m)
        return QL(lson);
    return max(QL(rson) + sum[lc], lm[lc]);
}
int QR(int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R)
        return rm[n];
    int m = l + r >> 1, ans;
    if (L > m)
        return QR(rson);
    if (R <= m)
        return QR(lson);
    return max(QR(lson) + sum[rc], rm[rc]);
}
int Q(int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R)
        return mm[n];
    int m = l + r >> 1, ans;
    if (L > m)
        return Q(rson);
    if (R <= m)
        return Q(lson);
    return max(QR(lson) + QL(rson), max(Q(lson), Q(rson)));
}
int main() {
    int m, q;
    scanf("%d", &N), B();
    scanf("%d", &m);
    while (m--) {
        scanf("%d%d%d", &q, &L, &R);
        if (q)
            printf("%d\n", Q());
        else
            U();
    }
    return 0;
}

// 8. SPOJ GSS1
int N, sum[MX], mm[MX << 2], lm[MX << 2], rm[MX << 2];
int get(int l, int r) {
    return sum[r] - sum[l - 1];
}
void B(int l = 1, int r = N, int n = 1) {
    if (l == r) {
        scanf("%d", &mm[n]);
        lm[n] = rm[n] = mm[n];
        sum[l] = sum[l - 1] + mm[n];
        return;
    }
    int m = l + r >> 1;
    B(lson), B(rson);
    lm[n] = max(lm[lc], get(l, m) + lm[rc]);
    rm[n] = max(rm[rc], get(m + 1, r) + rm[lc]);
    mm[n] = max(rm[lc] + lm[rc], max(mm[lc], mm[rc]));
}
int QL(int L, int R, int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R)
        return lm[n];
    int m = l + r >> 1, ans;
    if (L > m)
        return QL(L, R, rson);
    if (R <= m)
        return QL(L, R, lson);
    return max(QL(m + 1, R, rson) + get(L, m), max(get(L, m), QL(L, m, lson)));
}
int QR(int L, int R, int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R)
        return rm[n];
    int m = l + r >> 1, ans;
    if (L > m)
        return QR(L, R, rson);
    if (R <= m)
        return QR(L, R, lson);
    return max(QR(L, m, lson) + get(m + 1, R),
               max(get(m + 1, R), QR(m + 1, R, rson)));
}
int Q(int L, int R, int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R)
        return mm[n];
    int m = l + r >> 1, ans;
    if (L > m)
        return Q(L, R, rson);
    if (R <= m)
        return Q(L, R, lson);
    return max(QR(L, m, lson) + QL(m + 1, R, rson),
               max(Q(L, m, lson), Q(m + 1, R, rson)));
}
int main() {
    int m, L, R;
    scanf("%d", &N), B();
    scanf("%d", &m);
    while (m--)
        scanf("%d%d", &L, &R), printf("%d\n", Q(L, R));
    return 0;
}

// 9. 区间更新与赋值
ll sum[MX << 2], add[MX << 2], V;
bool se[MX << 2];
int L, R, N;
inline void up(int n) {
    sum[n] = sum[lc] + sum[rc];
}
void B(int l = 1, int r = N, int n = 1) {
    add[n] = 0;
    se[n] = false;
    if (l == r) {
        sum[n] = 0;
        return;
    }
    int m = (l + r) >> 1;
    B(ls), B(rs), up(n);
}
void down(int n, int m) {
    if (se[n]) {
        se[lc] = se[rc] = se[n];
        sum[lc] = sum[rc] = 0;
        se[n] = false;
        add[lc] = add[rc] = 0;
    }
    if (add[n]) {
        add[lc] += add[n];
        add[rc] += add[n];
        sum[lc] += add[n] * (m - (m >> 1));
        sum[rc] += add[n] * (m >> 1);
        add[n] = 0;
    }
}
void U(int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R) {
        add[n] += V, sum[n] += V * (r - l + 1);
        return;
    }
    down(n, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m)
        U(ls);
    if (m < R)
        U(rs);
    up(n);
}
void S(int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R) {
        se[n] = true, add[n] = false, sum[n] = 0;
        return;
    }
    down(n, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m)
        S(ls);
    if (m < R)
        S(rs);
    up(n);
}
ll Q(int l = 1, int r = N, int n = 1) {
    if (L <= l && r <= R) {
        return sum[n];
    }
    down(n, r - l + 1);
    ll ans = 0, m = (l + r) >> 1;
    if (L <= m)
        ans += Q(ls);
    if (m < R)
        ans += Q(rs);
    return ans;
}
int main() {
    int t, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &N, &m), B();
        ll ans = 0;
        int p = 0, q = 0;
        while (m--) {
            scanf("%d", &q);
            L = 1, R = N, V = q - p;
            U(), p = q;
            scanf("%d%d", &L, &R);
            ans += Q(), S();
        }
        printf("%lld\n", ans);
    }
    return 0;
}

// 10. UVA 1400
typedef long long ll;
typedef pair<int, int> seg;
ll sum[MX];
int pre[MX << 2], suf[MX << 2];
seg sub[MX << 2];
ll get(int l, int r) {
    return sum[r] - sum[l - 1];
}
ll get(seg s) {
    return get(s.first, s.second);
}
seg max(seg a, seg b) {
    if (get(a) != get(b))
        return get(a) > get(b) ? a : b;
    return a < b ? a : b;
}
void pushUp(int l, int r, int n) {
    ll v1 = get(l, pre[n << 1]), v2 = get(l, pre[n << 1 | 1]);
    if (v1 == v2)
        pre[n] = min(pre[n << 1], pre[n << 1 | 1]);
    else
        pre[n] = v1 > v2 ? pre[n << 1] : pre[n << 1 | 1];
    v1 = get(suf[n << 1], r), v2 = get(suf[n << 1 | 1], r);
    if (v1 == v2)
        suf[n] = min(suf[n << 1], suf[n << 1 | 1]);
    else
        suf[n] = v1 > v2 ? suf[n << 1] : suf[n << 1 | 1];
    sub[n] = max(make_pair(suf[n << 1], pre[n << 1 | 1]),
                 max(sub[n << 1], sub[n << 1 | 1]));
}
void build(int l, int r, int n) {
    if (l == r) {
        pre[n] = suf[n] = l, sub[n] = make_pair(l, l);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushUp(l, r, n);
}
seg prefix(int L, int R, int l, int r, int n) {
    if (pre[n] <= R)
        return make_pair(l, pre[n]);
    int m = (l + r) >> 1;
    if (R <= m)
        return prefix(L, R, lson);
    seg ans = prefix(L, R, rson);
    ans.first = l;
    return max(ans, make_pair(l, pre[n << 1]));
}
seg suffix(int L, int R, int l, int r, int n) {
    if (suf[n] >= L)
        return make_pair(suf[n], r);
    int m = (l + r) >> 1;
    if (L > m)
        return suffix(L, R, rson);
    seg ans = suffix(L, R, lson);
    ans.second = r;
    return max(ans, make_pair(suf[n << 1 | 1], r));
}
seg query(int L, int R, int l, int r, int n) {
    if (L <= l && r <= R)
        return sub[n];
    int m = (l + r) >> 1;
    if (R <= m)
        return query(L, R, lson);
    if (L > m)
        return query(L, R, rson);
    return max(max(query(L, R, lson), query(L, R, rson)),
               make_pair(suffix(L, R, lson).first, prefix(L, R, rson).second));
}
int main() {
    int cas = 0, n, m, a, b;
    while (~scanf("%d%d", &n, &m)) {
        sum[0] = 0;
        for (int i = 0; i < n; ++i)
            scanf("%d", &a), sum[i + 1] = sum[i] + a;
        build(1, n, 1);
        printf("Case %d:\n", ++cas);
        while (m--) {
            scanf("%d%d", &a, &b);
            seg ans = query(a, b, 1, n, 1);
            printf("%d %d\n", ans.first, ans.second);
        }
    }
    return 0;
}