1. LA 3787 Jupiter Attacks
单点赋值，查询区间哈希值。

ll b, p, c[MX << 2], s[MX];
void up() {
    c[n] = (c[lc] * s[r - m] + c[rc]) % p;
}
ll Q(int l = 1, int r = N, int n = 1) {
    if (x <= l && r <= y) {
        return c[n] * s[y - r];
    }
    ...
    return ans % p;
}
void init() {
    s[0] = 1;
    for (int i = 1; i <= N; ++i)
        s[i] = (s[i - 1] * b) % p;
    memset(c, 0, sizeof(c));
}

2. 扫描线

3. URI 1477
区间更新与赋值。
