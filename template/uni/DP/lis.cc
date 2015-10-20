int lis[MAXN];
int lis() {
    int n, i, j, x, len = 0;
    for (i = 1; i <= n; ++i) {
        scanf("%d", &x);  // 或者 x = num[i]
        j = lower_bound(lis + 1, lis + len + 1, x) - lis;
        // LDS：j = lower_bound(lds + 1, lds + len + 1, x, greater<int>()) - lds;
        lis[j] = x;
        len = max(len, j);
    }
    return len;
}
// 打印路径: 使用 pos 数组，从后往前扫，(len--)的第一次出现就是答案
// LIS[i] = max{1 , LIS[k] + 1}  (∀k < i, arr[i] > arr[k])
/*
Longest Not-decrease Sequence:
bool cmp(int a, int b) {
    return a <= b;
}
j = lower_bound(lis + 1, lis + len + 1, x, cmp) - lis;
*/
