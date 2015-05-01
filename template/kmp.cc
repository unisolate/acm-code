int m, n, p[10010];
char a[1000100], b[10010];
void init() {
    p[0] = -1;
    int i = 0, j = -1;
    while (i < n)
        if (j == -1 || b[i] == b[j])
            ++i, ++j, p[i] = j;
        else j = p[j];
}
int kmp() {
    int i = 0, j = 0, ans = 0;
    while (i < m) {
        if (j == -1 || b[j] == a[i])
            ++i, ++j;
        else j = p[j];
        if (j == n)
            ++ans;
    }
    return ans;
}