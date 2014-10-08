//===========================NetworkCostFlowZkw========

const int NCFZmaxn = 10005;
const int NCFZmaxm = 100005;
const int NCFZinf_ = 0x7f;
const int NCFZinf  = 0x7f7f7f7f;

struct NCFZ_Line
{
  int fr, to, next, v, c, opt;
};

struct Network_Cost_Flow_Zkw
{
  NCFZ_Line li[NCFZmaxm];
  int be[NCFZmaxn], l, s, t, dist[NCFZmaxn], b[NCFZmaxn];
  deque<int> q;

  void makeline(int fr, int to, int v, int c)
  {
    ++l;
    li[l].next = be[fr];
    be[fr] = l;
    li[l].fr = fr;
    li[l].to = to;
    li[l].v = v;
    li[l].c = c;
    li[l].opt = l + 1;

    ++l;
    li[l].next = be[to];
    be[to] = l;
    li[l].fr = to;
    li[l].to = fr;
    li[l].v = 0;
    li[l].c = -c;
    li[l].opt = l - 1;
  }

  void create()
  {
  }

  void clear()
  {
    l = s = t = 0;
    memset(be, 0, sizeof(be));
    memset(b, 0, sizeof(b));
  }

  bool spfa()
  {
    memset(dist, NCFZinf_, sizeof(dist));
    memset(b, 0, sizeof(b));
    dist[t] = 0;
    b[t] = 1;
    q.push_back(t);
    while (!q.empty())
    {
      int now = q.front();
      q.pop_front();
      for (int i = be[now]; i; i = li[i].next)
      {
        int to = li[i].to;
        if (!li[li[i].opt].v || dist[to] <= dist[now] - li[i].c) continue;
        dist[to] = dist[now] - li[i].c;
        if (!b[to])
        {
          b[to] = 1;
          if (!q.empty() && dist[to] < dist[q.front()]) q.push_front(to);
          else q.push_back(to);
        }
      }
      b[now] = 0;
    }
    return dist[s] != NCFZinf;
  }

  int sap(int now, int maxf)
  {
    if (now == t) return maxf;
    int tot = 0;
    b[now] = 1;
    for (int i = be[now]; i; i = li[i].next)
    {
      int to = li[i].to;
      if (!b[to] && li[i].v && dist[to] == dist[now] - li[i].c)
      {
        int k = sap(to, min(maxf - tot, li[i].v));
        li[i].v -= k;
        li[li[i].opt].v += k;
        tot += k;
      }
    }
    return tot;
  }

  par query(int S, int T)
  {
    par ans;
    ans.a = ans.b = 0;
    s = S, t = T;
    while (spfa())
      while (int k = sap(s, NCFZinf))
      {
        memset(b, 0, sizeof(b));
        ans.a += k;
        ans.b += k * dist[s];
      }
    return ans;
  }
};

//===========================NetworkCostFlowZkw========
