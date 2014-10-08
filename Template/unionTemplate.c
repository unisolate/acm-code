int p[MAXN];
void init()
{
    for (int i = 0; i < MAXN; ++i)
        p[i] = i;
}
int find(int x)
{
    return x == p[x] ? x : (p[x] = find(p[x]));
}
bool equal(int x, int y) // whether at same group
{
    return find(x) == find(y);
}
void union(int x, int y)
{
    p[find(x)] = find(y);
}
void union(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    num--;
    p[x] = y;
}

int n[10];  // 每個頭目帶領的人數
void init()
{
    for (int i = 0; i < 10; i++)
    {
        g[i] = i;
        n[i] = 1;   // 頭目有第 0 到第 9 人，每團都是一個人。
    }
}
void union(int x, int y)
{
    x = find(x); y = find(y);
    if (x == y) return;
    groups--;
    n[y] += n[x];   // 新頭目吸收人數
    n[x] = 0;       // 舊頭目不再帶領人
    p[x] = y;
}
int cardinality(int x)
{
    return n[find(x)];
}
bool single(int x)
{
    return n[find(x)] == 1;
}