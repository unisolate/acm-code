// [l, r]
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

// [l, r)
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

/*
[l, r)
lower_bound >=
upper_bound >
 */

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

void solve(int l, int r) {
    int m;
    while (r - l > 1) {
        m = (l + r) >> 1;
        ok(m) ? l = m : r = m;
    }
    return l;
}