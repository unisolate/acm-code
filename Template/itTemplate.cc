#define m ((l+r)>>1)
#define lo o<<1
#define ro o<<1|1
#define lc lo,l,m
#define rc ro,m+1,r

const int MX = int(1e5);
const int inf = 0x5fffffff;

int node[MX << 2], sumv[MX << 2], minv[MX << 2], maxv[MX << 2], setv[MX << 2], addv[MX << 2];
int ql, qr, n, chgv, add;

int maintain(int o, int l, int r)
{
    sumv[o] = minv[o] = maxv[o] = 0;
    if (l < r)
    {
        sumv[o] = sumv[lo] + sumv[ro];
        minv[o] = min(minv[lo], minv[ro]);
        maxv[o] = max(maxv[lo], maxv[ro]);
    }
    sumv[o] += addv[o] * (r - l + 1);       //区间加减
    minv[o] += addv[o];                     //区间加减
    maxv[o] += addv[o];                     //区间加减
}

void pushdown(int o)
{
    //    if (addv[o]){                           //区间加减
    //        addv[lo]+=addv[o];                  //区间加减
    //        addv[ro]+=addv[o];                  //区间加减
    //        addv[o]=0;                          //区间加减
    //    }                                       //区间加减
    if (~setv[o])                           //区间赋值
    {
        setv[lo] = setv[ro] = setv[o];      //区间赋值
        setv[o] = -1;                       //区间赋值
        setv[lo] = setv[ro] = 0;            //同时出现赋值、加减
    }                                       //区间赋值
}

void U(int o = 1, int l = 1, int r = n)
{
    if (ql <= l && r <= qr)
    {
        //        sumv[o]=minv[o]=maxv[o]=chgv;       //单点更新
        //        addv[o]+=add;                       //区间加减
        setv[o] = chgv;                     //区间赋值
        return;
    }
    pushdown(o);                            //区间加减|区间赋值
    if (ql <= m) U(lc);
    else maintain(lc);                      //区间加减
    if (qr > m) U(rc);
    else maintain(rc);                      //区间加减
    maintain(o, l, r);
}


int _min = inf, _max = -inf, _sum = 0;
void Q(int o = 1, int l = 1, int r = n, int add)
{
    if (~setv[o])                               //区间赋值
    {
        _sum += setv[o] * (min(qr, r) - max(l, ql) + 1); //区间赋值
        _max = max(_max, setv[o]);              //区间赋值
        _min = min(_min, setv[o]);              //区间赋值
        return;
    }
    if (ql <= l && r <= qr)
    {
        //        _sum+=sumv[o];                      //单点更新
        //        _max=max(_max,maxv[o]);             //单点更新
        //        _min=min(_min,minv[o]);             //单点更新
        _sum += sumv[o] + add * (r - l + 1); //区间加减
        _max = max(_max, maxv[o] + add);    //区间加减
        _min = min(_min, minv[o] + add);    //区间加减
    }
    //    if (ql<=m) Q(lc);                       //单点更新
    //    if (qr>m) Q(rc);                        //单点更新
    if (ql <= m) Q(lc, add + addv[o]);      //区间加减
    if (qr > m) Q(rc, add + addv[o]);       //区间加减
}
