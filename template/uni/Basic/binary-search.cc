// 二分查找，区间 [l, r]
int bs(int k) {
    int l = 0, r = n - 1, p;
    while (l <= r) {
        p = (l + r) >> 1;
        if (a[p] == k)
            return p;
        if (a[p] < k)
            l = p + 1;
        else
            r = p - 1;
    }
    return -1;
}

// 二分查找，区间 [l, r)
int bs(int k) {
    int l = 0, r = n, p;
    while (l < r) {
        p = (l + r) >> 1;
        if (a[p] == k)
            return p;
        if (a[p] < k)
            l = p + 1;
        else
            r = p;
    }
    return -1;
}

// lower_bound（第一个 >=）区间 [l, r)
// STL 排序
bool cmp(const A &x, const A &y) {
    return x.v < y.v;
}

int lb(int k) {
    int cnt = r - l, it, step;
    while (cnt > 0) {
        step = cnt / 2;
        it = l + step;
        if (a[it] < k) {
            l = ++it;
            cnt -= step + 1;
        } else {
            cnt = step;
        }
    }
    return l;
}

// upper_bound（第一个 >）区间 [l, r)
int ub(int k) {
    int cnt = r - l, it, step;
    while (cnt > 0) {
        step = cnt / 2;
        it = l + step;
        if (a[it] <= k) {
            l = ++it;
            cnt -= step + 1;
        } else {
            cnt = step;
        }
    }
    return l;
}

// 二分查找答案 区间 [l, r)
void solve(int l, int r) {
    int m;
    while (r - l > 1) {
        m = (l + r) >> 1;
        ok(m) ? l = m : r = m;
    }
    return l;
}

// 二分迭代
double l = 0, r = 1, m;
for (int i = 0; i < 100; ++i) {
    m = (l + r) / 2.0;
    ok(m) ? l = m : r = m;
}

// 三分查找答案
double l = 0, r = INF, tmp, m1, m2;
while (l + eps < r) {
    tmp = (r - l) / 3.0;
    m1 = l + tmp;
    m2 = r - tmp;
    calc(m1) > calc(m2) + eps ? l = m1 : r = m2;
}
printf("Case #%d: %.2lf %.2lf\n", cas++, l, calc(l));