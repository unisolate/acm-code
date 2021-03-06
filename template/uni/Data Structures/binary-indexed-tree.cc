// 1. 单点
// 每次用之前 memset
int c[MX];

// 不判 0 可能操蛋
void U(int x, int v) {
    if (x == 0) {
        return;
    }
    for (; x <= n; x += (x & -x))
        c[x] += v;
}

// [1,x]的和
int Q(int x) {
    if (x == 0) {
        return;
    }
    int r = 0;
    for (; x > 0; x -= (x & -x))
        r += c[x];
    return r;
}

// 2. 二维
int c[MAXX][MAXY];

// 更新 (x,y)
void U(int x, int y, int v) {
    for (; x <= MAXX; x += (x & -x))
        for (int i = y; i <= MAXY; i += (i & -i))
            c[x][i] += v;
}

// (1,1) 到 (x,y) 的和
int Q(int x, int y) {
    int r = 0;
    for (; x > 0; x -= (x & -x))
        for (int i = y; i > 0; i -= (i & -i))
            r += c[x][i];
    return r;
}

// 3. 区间更新 [l,r]
// U(l - 1, -c), U(r, c);
void U(int x, int v) {
    for (; x > 0; x -= (x & -x))
        b[x] += v;
}

// Q(x) 查询 a[x] 的值
int Q(int x) {
    int r = 0;
    for (; x <= n; x += (x & -x))
        r += b[x];
    return r;
}

/// 4. 区间更新、查询
// 更新[l,r]：U(r, c); if (l > 1) U(l - 1, -c);
void U(int x, int v) {
    if (x == 0)
        return;
    for (int i = x; i > 0; i -= (i & -i))
        b[i] += v;
    for (int i = x; i <= n; i += (i & -i))
        c[i] += x * v;
}

// 查询[l,r]：Q(r) - Q(l - 1);
int QB(int x) {
    int r = 0;
    for (; x <= n; x += (x & -x))
        r += b[x];
    return r;
}

int QC(int x) {
    int r = 0;
    for (; x > 0; x -= (x & -x))
        r += c[x];
    return r;
}

int Q(int x) {
    if (x)
        return QB(x) * x + QC(x - 1);
    return 0;
}

// 5. 带重复的逆序对，最大 10^9
#define MX 99999
typedef long long ll;
struct P {
    int v, w, i;
} p[MX];
int c[MX];
int x(P a, P b) {
    return a.v < b.v;
}
int y(P a, P b) {
    return a.i > b.i;
}
void U(int i) {
    for (; i < MX; i += i & -i)
        ++c[i];
}
int Q(int i) {
    int r = 0;
    for (; i > 0; i -= i & -i)
        r += c[i];
    return r;
}
int main() {
    int n, k;
    while (~scanf("%d", &n)) {
        ll a = 0;
        k = 1;
        memset(c, 0, sizeof(c));
        for (int i = 0; i < n; ++i)
            scanf("%d", &p[i].v), p[i].i = i;
        sort(p, p + n, x);
        p[0].w = k;
        for (int i = 1; i < n; ++i)
            p[i].w = p[i].v == p[i - 1].v ? k : ++k;
        sort(p, p + n, y);
        for (int i = 0; i < n; ++i)
            a += Q(p[i].w - 1), U(p[i].w);
        printf("%I64d\n", a);
    }
    return 0;
}