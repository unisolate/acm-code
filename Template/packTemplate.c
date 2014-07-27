int f[MAXN], c[MAXN], w[MAXN];
//c -> space, w -> value

int v, n;
//v -> pack space, n -> number of objects

int zeroPack()
{
    memset(f, 0, sizeof(f));
    for(int i = 1; i < n; ++i)
        for(int j = v; j >= c[i]; --j)
            f[j] = max(f[j], f[j - c[i]] + w[i]);
    return f[v];
}

int completePack()
{
    memset(f, 0, sizeof(f));
    for(int i = 1; i < n; ++i)
        for(int j = c[i]; j <= v; ++j)
            f[j] = max(f[j], f[j - c[i]] + w[i]);
    return f[v];
}
