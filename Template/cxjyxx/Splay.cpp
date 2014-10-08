//===========================Splay=====================

const int SPLAYmaxn = 200005;
const int SPLAYinf = 100000000;

struct Splay_Node
{
  int l, r, fa, v, sum;
};

struct Splay
{
  Splay_Node t[SPLAYmaxn];
  int root, tot;

  void clear(int a)
  {
    t[a].l = t[a].r = t[a].fa = t[a].v = t[a].sum = 0;
  }

  void create()
  {
    clear(1), clear(2);
    root = 1, tot = 2;
    t[1].v = -SPLAYinf;
    t[2].v = SPLAYinf;
    t[1].r = t[1].sum = 2;
    t[2].fa = t[2].sum = 1;
  }

  void up(int now)
  {
    t[now].sum = t[t[now].l].sum + t[t[now].r].sum + 1;
  }

  void left(int now)
  {
    int fa = t[now].fa;
    t[now].fa = t[fa].fa;
    if (t[t[fa].fa].l == fa) t[t[fa].fa].l = now;
    if (t[t[fa].fa].r == fa) t[t[fa].fa].r = now;
    t[fa].fa = now;
    t[fa].r = t[now].l;
    t[t[now].l].fa = fa;
    t[now].l = fa;
    up(fa);
  }

  void right(int now)
  {
    int fa = t[now].fa;
    t[now].fa = t[fa].fa;
    if (t[t[fa].fa].l == fa) t[t[fa].fa].l = now;
    if (t[t[fa].fa].r == fa) t[t[fa].fa].r = now;
    t[fa].fa = now;
    t[fa].l = t[now].r;
    t[t[now].r].fa = fa;
    t[now].r = fa;
    up(fa);
  }

  void splay(int now, int FA = 0)
  {
    while (t[now].fa != FA)
    {
      int fa = t[now].fa;
      if (t[fa].fa == FA)
        if (t[fa].l == now) right(now);
        else left(now);
      else
        if (t[t[fa].fa].l == fa)
          if (t[fa].l == now) right(fa), right(now);
          else left(now), right(now);
        else
          if (t[fa].l == now) right(now), left(now);
          else left(fa), left(now);
    }
    up(now);
    if (!FA) root = now;
  }

  int lower_bound(int v)
  {
    int ans = 0, la = 0;
    for (int now = root; now;)
    {
      la = now;
      if (t[now].v >= v) ans = now, now = t[now].l;
      else now = t[now].r;
    }
    splay(la);
    return ans;
  }

  void insert(int v)
  {
    for (int now = root;;)
    {
      ++t[now].sum;
      if (t[now].v >= v)
        if (t[now].l) now = t[now].l;
        else
        {
          t[now].l = ++tot;
          clear(tot);
          t[tot].sum = 1;
          t[tot].fa = now;
          t[tot].v = v;
          splay(tot);
          return;
        }
      else
        if (t[now].r) now = t[now].r;
        else
        {
          t[now].r = ++tot;
          clear(tot);
          t[tot].sum = 1;
          t[tot].fa = now;
          t[tot].v = v;
          splay(tot);
          return;
        }
    }
  }

  int get_lower(int a)
  {
    splay(a);
    for (a = t[a].l; t[a].r; a = t[a].r);
    return a;
  }

  int get_upper(int a)
  {
    splay(a);
    for (a = t[a].r; t[a].l; a = t[a].l);
    return a;
  }

  int get_rank(int a)
  {
    splay(a);
    return t[t[a].l].sum;
  }

  void del(int l, int r)
  {
    l = get_lower(l);
    r = get_upper(r);
    splay(l);
    splay(r, l);
    t[r].l = 0;
    up(r);
    up(l);
  }

  int get_kth(int k)
  {
    ++k;
    for (int now = root;;)
    {
      if (t[t[now].l].sum == k - 1)
        return now;
      if (t[t[now].l].sum >= k) now = t[now].l;
      else k -= t[t[now].l].sum + 1, now = t[now].r;
    }
  }
};

//===========================Splay=====================
