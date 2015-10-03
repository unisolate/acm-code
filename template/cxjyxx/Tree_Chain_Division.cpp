//===========================TreeChainDivision=========

const int TCDmaxn = 100005;

struct Tree_Chain_Division
{
  private:
  Segment_Tree t;
  int last[TCDmaxn], d[TCDmaxn], to[TCDmaxn], sum[TCDmaxn], fa[TCDmaxn], p, tot, a[TCDmaxn], n;
  queue<par> q;
  stack<int> s;

  void build(Link_Table_V &L)
  {
    q.push(par(1, 0));
    d[1] = 1;
    while (!q.empty())
    {
      par now = q.front();
      q.pop();
      s.push(now.a);
      for (int i = L.be(now.a); i; i = L.next(i))
      {
        int to = L.to(i);
        if (to == now.b) continue;
        d[to] = d[now.a] + 1;
        fa[to] = now.a;
        q.push(par(to, now.a));
      }
    }
    while (!s.empty())
    {
      int now = s.top();
      s.pop();
      for (int i = L.be(now); i; i = L.next(i))
      {
        int to = L.to(i);
        if (d[to] == d[now] - 1) continue;
        sum[now] += sum[to];
      }
      ++sum[now];
    }
    q.push(par(1, 1));
    a[to[1] = 1] = 0;
    last[1] = 1;
    while (!q.empty())
    {
      par now = q.front();
      q.pop();
      if (sum[now.a] == 1) continue;
      int mx = 0;
      ++now.b;
      for (int i = L.be(now.a); i; i = L.next(i))
      {
        int to = L.to(i);
        if (d[to] == d[now.a] - 1) continue;
        if (sum[L.to(mx)] < sum[to]) mx = i;
      }
      a[to[L.to(mx)] = now.b] = L.v(mx);
      q.push(par(L.to(mx), now.b));
      now.b += sum[L.to(mx)];
      last[L.to(mx)] = last[now.a];
      for (int i = L.be(now.a); i; i = L.next(i))
      {
        int _to = L.to(i);
        if (i == mx || d[_to] == d[now.a] - 1) continue;
        a[to[_to] = now.b] = L.v(i);
        q.push(par(_to, now.b));
        now.b += sum[_to];
        last[_to] = _to;
      }
    }
  }

  void build(Link_Table &L, int v[])
  {
    q.push(par(1, 0));
    d[1] = 1;
    while (!q.empty())
    {
      par now = q.front();
      q.pop();
      s.push(now.a);
      for (int i = L.be(now.a); i; i = L.next(i))
      {
        int to = L.to(i);
        if (to == now.b) continue;
        d[to] = d[now.a] + 1;
        fa[to] = now.a;
        q.push(par(to, now.a));
      }
    }
    while (!s.empty())
    {
      int now = s.top();
      s.pop();
      for (int i = L.be(now); i; i = L.next(i))
      {
        int to = L.to(i);
        if (d[to] == d[now] - 1) continue;
        sum[now] += sum[to];
      }
      ++sum[now];
    }
    q.push(par(1, 1));
    a[to[1] = 1] = v[1];
    last[1] = 1;
    while (!q.empty())
    {
      par now = q.front();
      q.pop();
      if (sum[now.a] == 1) continue;
      int mx = 0;
      ++now.b;
      for (int i = L.be(now.a); i; i = L.next(i))
      {
        int to = L.to(i);
        if (d[to] == d[now.a] - 1) continue;
        if (sum[L.to(mx)] < sum[to]) mx = i;
      }
      a[to[L.to(mx)] = now.b] = v[L.to(mx)];
      q.push(par(L.to(mx), now.b));
      now.b += sum[L.to(mx)];
      last[L.to(mx)] = last[now.a];
      for (int i = L.be(now.a); i; i = L.next(i))
      {
        int _to = L.to(i);
        if (i == mx || d[_to] == d[now.a] - 1) continue;
        a[to[_to] = now.b] = v[_to];
        q.push(par(_to, now.b));
        now.b += sum[_to];
        last[_to] = _to;
      }
    }
  }

  int qy_sum(int u, int num)
  {
    if (!num) return 0;
    if (d[u] - d[last[u]] + 1 >= num) return t.query_sum(to[u] - num + 1, to[u]);
    else return qy_sum(fa[last[u]], num - (d[u] - d[last[u]] + 1)) + t.query_sum(to[last[u]], to[u]);
  }

  int qy_max(int u, int num)
  {
    if (!num) return 0;
    if (d[u] - d[last[u]] + 1 >= num) return t.query_max(to[u] - num + 1, to[u]);
    else return max(qy_max(fa[last[u]], num - (d[u] - d[last[u]] + 1)), t.query_max(to[last[u]], to[u]));
  }

  int qy_min(int u, int num)
  {
    if (!num) return 0;
    if (d[u] - d[last[u]] + 1 >= num) return t.query_min(to[u] - num + 1, to[u]);
    else return min(qy_min(fa[last[u]], num - (d[u] - d[last[u]] + 1)), t.query_min(to[last[u]], to[u]));
  }

  void my_sum(int u, int num, int va)
  {
    if (!num) return;
    if (d[u] - d[last[u]] + 1 >= num) t.modify_sum(to[u] - num + 1, to[u], va);
    else my_sum(fa[last[u]], num - (d[u] - d[last[u]] + 1), va), t.modify_sum(to[last[u]], to[u], va);
  }

  void my_is(int u, int num, int va)
  {
    if (!num) return;
    if (d[u] - d[last[u]] + 1 >= num) t.modify_is(to[u] - num + 1, to[u], va);
    else my_is(fa[last[u]], num - (d[u] - d[last[u]] + 1), va), t.modify_is(to[last[u]], to[u], va);
  }

  public:

  int lca(int u, int v)
  {
    while (last[u] != last[v])
    {
      if (d[last[u]] < d[last[v]]) swap(u, v);
      u = fa[last[u]];
    }
    if (d[u] > d[v]) swap(u, v);
    return u;
  }

  int query_sum(int u, int v)
  {
    int c = lca(u, v);
    if (p)
      return qy_sum(u, d[u] - d[c]) + qy_sum(v, d[v] - d[c]);
    else
      return qy_sum(u, d[u] - d[c]) + qy_sum(v, d[v] - d[c] + 1);
  }

  int query_max(int u, int v)
  {
    int c = lca(u, v);
    if (p)
      return max(qy_max(u, d[u] - d[c]), qy_max(v, d[v] - d[c]));
    else
      return max(qy_max(u, d[u] - d[c]), qy_max(v, d[v] - d[c] + 1));
  }

  int query_min(int u, int v)
  {
    int c = lca(u, v);
    if (p)
      return min(qy_min(u, d[u] - d[c]), qy_min(v, d[v] - d[c]));
    else
      return min(qy_min(u, d[u] - d[c]), qy_min(v, d[v] - d[c] + 1));
  }

  void modify_sum(int u, int v, int va)
  {
    int c = lca(u, v);
    if (p)
      my_sum(u, d[u] - d[c], va), my_sum(v, d[v] - d[c], va);
    else
      my_sum(u, d[u] - d[c], va), my_sum(v, d[v] - d[c] + 1, va);
  }

  void modify_is(int u, int v, int va)
  {
    int c = lca(u, v);
    if (p)
      my_is(u, d[u] - d[c], va), my_is(v, d[v] - d[c], va);
    else
      my_is(u, d[u] - d[c], va), my_is(v, d[v] - d[c] + 1, va);
  }

  void create(int N, Link_Table_V &L)
  {
    p = 1;
    n = N;
    build(L);
    t.create(1, n, a);
  }

  void create(int N, Link_Table &L, int a[])
  {
    p = 0;
    n = N;
    build(L, a);
    t.create(1, n, a);
  }
};

//===========================TreeChainDivision=========
