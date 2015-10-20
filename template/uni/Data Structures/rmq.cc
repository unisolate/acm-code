// st 算法更快，树状数组空间小。
// RMQ    初始化     查询     空间
// st算法  O(nlogn)  O(1)    O(nlogn)
// 树状数组 O(nlogn)  O(logn) O(n)
// st 算法
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

// 树状数组
int p[MX], d[MX];
void init(int n) {
    for (int i = 1; i < n; ++i) {
        d[i] = p[i];
        for (int j = 1; j < (i & -i); j <<= 1)
            d[i] = max(d[i], d[i - j]);
    }
}
int rmq(int x, int y) {
    if (x > y)
        return 0;
    int ans = p[y];
    while (1) {
        ans = max(ans, p[y]);
        if (x == y)
            break;
        for (y -= 1; y - x >= (y & -y); y -= (y & -y))
            ans = max(ans, d[y]);
    }
    return ans;
}