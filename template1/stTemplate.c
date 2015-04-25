#define lson l,m,n<<1
#define rson m+1,r,n<<1|1

int num[MX], sum[MX << 2], max[MX << 2], add[MX << 2];

void pushUp(int n)
{
    sum[n] = sum[n << 1] + sum[n << 1 | 1];
    max[n] = max(max[n << 1], max[n << 1 | 1]);
}

void build(int l, int r, int n)
{
    add[n] = 0;
    if (l == r)
    {
        scanf("%d", &num[n]);
        sum[n] = max[n] = num[n];
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushUp(n);
}

//update only one point
void update(int x, int v, int l, int r, int n)
{
    if (l == r)
    {
        //oprate here
        return;
    }
    int m = (l + r) >> 1;
    if (x <= m) //Very Important
        update(x, v, lson);
    else update(x, v, rson);
    pushUp(n);
}

//get sum or max val of [L,R]
int query(int L, int R, int l, int r, int n)
{
    if (L <= l && r <= R)
    {
        return sum[n];
        // return max[n];
    }
    int ans = 0, m = (l + r) >> 1;
    if (L <= m)
        ans += query(L, R, lson);
    // ans=max(ans,query(L,R,lson));
    if (m < R)
        ans += query(L, R, rson);
    // ans=max(ans,query(L,R,rson));
    return ans;
}

void pushDown(int n, int m)
{
    if (add[n])
    {
        add[n << 1] += add[n];
        add[n << 1 | 1] += add[n];
        sum[n << 1] += add[n] * (m - (m >> 1));
        sum[n << 1 | 1] += add[n] * (m >> 1);
        add[n] = 0;
    }
}

//update [L,R]
void update(int L, int R, int v, int l, int r, int n)
{
    if (L <= l && r <= R)
    {
        add[n] += v;
        sum[n] += v * (r - l + 1);
        return;
    }
    pushDown(n, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m)
        update(L, R, v, lson);
    if (m < R)
        update(L, R, v, rson);
    pushUp(n);
}

int query(int L, int R, int l, int r, int n)
{
    if (L <= l && r <= R)
    {
        return sum[n];
    }
    pushDown(n, r - l + 1);
    int m = (l + r) >> 1;
    int ans = 0;
    if (L <= m)
        ans += query(L, R, lson);
    if (m < R)
        ans += query(L, R, rson);
    return ans;
}
