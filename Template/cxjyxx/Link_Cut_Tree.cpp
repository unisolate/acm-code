//===========================LinkCutTree===============

const int LCTmaxn = 1000005;

struct LCT_Node
{
  int l, r, v, fa, lazy_swap, lazy_sum, sum, min, max, min_v, max_v, cnt;
  bool root;
};

struct Link_Cut_Tree
{
  private:

  LCT_Node t[LCTmaxn];
  int to[LCTmaxn], tot;
  queue<int> q;

  int mi(int a, int b) { return (a && (t[a].v < t[b].v || !b)) ? a : b; }
  int mx(int a, int b) { return (a && (t[a].v > t[b].v || !b)) ? a : b; }

  int mi2(int a, int a_v, int b, int b_v)  { return (a && (a_v < b_v || !b)) ? a : b; }
  int mx2(int a, int a_v, int b, int b_v)  { return (a && (a_v > b_v || !b)) ? a : b; }
  int miv2(int a, int a_v, int b, int b_v) { return (a && (a_v < b_v || !b)) ? a_v : b_v; }
  int mxv2(int a, int a_v, int b, int b_v) { return (a && (a_v > b_v || !b)) ? a_v : b_v; }

  void down(int now)
  {
    if (!now) return;
    if (t[now].lazy_swap)
    {
      swap(t[now].l, t[now].r);
      mdf_swap(t[now].l);
      mdf_swap(t[now].r);
      t[now].lazy_swap = 0;
    }
    if (t[now].lazy_sum)
    {
      int k = t[now].lazy_sum;
      t[now].lazy_sum = 0;
      t[now].sum += t[now].cnt * k;
      t[now].min_v += k;
      t[now].max_v += k;
      t[now].v += k;
      mdf_sum(t[now].l, k);
      mdf_sum(t[now].r, k);
    }
  }

  void up(int now)
  {
    if (!now) return;
    down(now), down(t[now].l), down(t[now].r);
    t[now].sum = t[t[now].l].sum + t[t[now].r].sum + t[now].v;
    t[now].cnt = t[t[now].l].cnt + t[t[now].r].cnt + 1;
    int mi = mi2(t[t[now].l].min, t[t[now].l].min_v, t[t[now].r].min, t[t[now].r].min_v),
        miv = miv2(t[t[now].l].min, t[t[now].l].min_v, t[t[now].r].min, t[t[now].r].min_v),
        mx = mx2(t[t[now].l].max, t[t[now].l].max_v, t[t[now].r].max, t[t[now].r].max_v),
        mxv = mxv2(t[t[now].l].max, t[t[now].l].max_v, t[t[now].r].max, t[t[now].r].max_v);
    t[now].min   =  mi2(now, t[now].v, mi, miv);
    t[now].min_v = miv2(now, t[now].v, mi, miv);
    t[now].max   =  mx2(now, t[now].v, mx, mxv);
    t[now].max_v = mxv2(now, t[now].v, mx, mxv);
  }

  void mdf_swap(int now)
  {
    if (!now) return;
    t[now].lazy_swap ^= 1;
  }

  void mdf_sum(int now, int v)
  {
    if (!now) return;
    t[now].lazy_sum += v;
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
    t[now].root = t[fa].root;
    t[fa].root = false;
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
    t[now].root = t[fa].root;
    t[fa].root = false;
    up(fa);
  }

  void splay(int now)
  {
    if (!now) return;
    down(now);
    while (!t[now].root)
    {
      int fa = t[now].fa;
      if (t[fa].root)
      {
        down(fa), down(now);
        if (t[fa].l == now) right(now);
        else left(now);
      }
      else
      {
        down(t[fa].fa), down(fa), down(now);
        if (t[t[fa].fa].l == fa)
          if (t[fa].l == now) right(fa), right(now);
          else left(now), right(now);
        else
          if (t[fa].l == now) right(now), left(now);
          else left(fa), left(now);
      }
    }
    up(now);
  }

  void bfs(int now, Link_Table &L, int a[])
  {
    to[now] = ++tot;
    q.push(now);
    while (!q.empty())
    {
      int now = q.front();
      q.pop();
      int p = to[now];
      t[p].root = true, t[p].v = t[p].sum = t[p].min_v = t[p].max_v = a[now], t[p].min = t[p].max = p, t[p].cnt = 1;
      for (int i = L.be(now); i; i = L.next(i))
      {
        int T = L.to(i);
        if (to[T]) continue;
        to[T] = ++tot;
        t[tot].fa = p;
        q.push(T);
      }
    }
  }

  void cut_imag(int now)
  {
    if (!now) return;
    int fa = t[now].fa;
    if (!fa) return;
    down(fa);
    if (t[fa].l == now) t[fa].l = 0;
    if (t[fa].r == now) t[fa].r = 0;
    t[now].root = true;
    up(fa);
  }

  void access(int now)
  {
    if (!now) return;
    splay(now);
    while (t[now].fa)
    {
      int fa = t[now].fa;
      splay(fa);
      cut_imag(t[fa].r);
      t[fa].r = now;
      t[now].root = false;
      up(fa);
      splay(now);
    }
    cut_imag(t[now].r);
  }

  int get_root(int now)
  {
    for (splay(now); t[now].l; now = t[now].l, down(now));
    //splay(now);
    return now;
  }

  int get_fa(int now)
  {
    for (splay(now), now = t[now].l, down(now); t[now].r; now = t[now].r, down(now));
    //splay(now);
    return now;
  }

  int lca(int u, int v)
  {
    access(u);
    splay(v);
    while (t[v].fa)
    {
      int fa = t[v].fa;
      splay(fa);
      cut_imag(t[fa].r);
      t[fa].r = v;
      t[v].root = false;
      up(fa);
      v = fa;
    }
    return v;
  }

  void mk_root(int now)
  {
    if (!now) return;
    access(now);
    mdf_swap(now);
    splay(now);
  }

  public:

  void make_root(int now)
  {
    now = to[now];
    mk_root(now);
  }

  void link(int u, int v)
  {
    u = to[u], v = to[v];
    mk_root(u);
    mk_root(v);
    splay(v);
    splay(u);
    t[v].fa = u;
    access(u);
  }

  void cut(int u, int v)
  {
    u = to[u], v = to[v];
    int c = lca(u, v);
    if (c == v) swap(u, v);
    access(v);
    splay(u);
    cut_imag(v);
    t[v].fa = 0;
  }

  int query_sum(int u, int v)
  {
    u = to[u], v = to[v];
    int c = lca(u, v), ans = 0;
    access(u);
    splay(c);
    down(t[c].r);
    ans += t[t[c].r].sum;
    access(v);
    splay(c);
    down(t[c].r);
    ans += t[t[c].r].sum + t[c].v;
    return ans;
  }

  int query_max(int u, int v)
  {
    u = to[u], v = to[v];
    int c = lca(u, v), ans = 0, ans_v = 0;
    access(u);
    splay(c);
    down(t[c].r);
    ans = mx2(t[t[c].r].max, t[t[c].r].max_v, c, t[c].v);
    ans_v = mxv2(t[t[c].r].max, t[t[c].r].max_v, c, t[c].v);
    access(v);
    splay(c);
    down(t[c].r);
    ans = mx2(ans, ans_v, t[t[c].r].max, t[t[c].r].max_v);
    return ans;
  }

  int query_min(int u, int v)
  {
    u = to[u], v = to[v];
    int c = lca(u, v), ans = 0, ans_v = 0;
    access(u);
    splay(c);
    down(t[c].r);
    ans = mi2(t[t[c].r].min, t[t[c].r].min_v, c, t[c].v);
    ans_v = miv2(t[t[c].r].min, t[t[c].r].min_v, c, t[c].v);
    access(v);
    splay(c);
    down(t[c].r);
    ans = mi2(ans, ans_v, t[t[c].r].min, t[t[c].r].min_v);
    return ans;
  }

  int root(int u)
  {
    u = to[u];
    access(u);
    return get_root(u);
  }

  void modify_sum(int u, int v, int value)
  {
    u = to[u], v = to[v];
    mk_root(u);
    access(v);
    mdf_sum(v, value);
  }

  void create(int n, Link_Table &L, int a[])
  {
    for (int i = 1; i <= n; ++i)
      if (!to[i])
        bfs(i, L, a);
  }

  void refresh(int now)
  {
    now = to[now];
    splay(now);
  }

  void clear()
  {
    memset(t, 0, sizeof(t));
    memset(to, 0, sizeof(to));
    tot = 0;
  }

  int get_v(int now)
  {
    splay(now);
    return t[now].v;
  }

  int to_num(int now)
  {
    return to[now];
  }
};

//===========================LinkCutTree===============
