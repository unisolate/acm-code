int p[MX], q[MX], n;
void init() {
    for (int i = 0; i < MX; ++i) {
        p[i] = i;
        q[i] = 1;
    }
}
int F(int x) {
    return x == p[x] ? x : (p[x] = F(p[x]));
}
// 同组
bool equal(int x, int y) {
    return F(x) == F(y);
}
void uni(int x, int y) {
    x = F(x), y = F(y);
    if (x == y)
        return;
    --n;
    p[x] = y;
    q[y] += q[x];
    q[x] = 0;
}