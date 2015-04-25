//===========================NetworkFlow===============

const int NFmaxn = 1005;
const int NFmaxm = 1005;
const int NFinf = 0x7fffffff;

struct NF_Line
{
  int to, next, v, opt;
};

struct Network_Flow
{
  NF_Line li[NFmaxm];
  int be[NFmaxn], l, s, t, n, num[NFmaxn], note[NFmaxn];

  void makeline(int fr, int to, int v)
  {
    ++l;
    li[l].next = be[fr];
    be[fr] = l;
    li[l].to = to;
    li[l].v = v;
    li[l].opt = l + 1;

    ++l;
    li[l].next = be[to];
    be[to] = l;
    li[l].to = fr;
    li[l].v = 0;
    li[l].opt = l - 1;
  }

  void create(int N)
  {
    n = N;
  }

  int sap(int now, int maxf)
  {
    if (now == t) return maxf;
    int mi = n, tot = 0;
    for (int i = be[now]; i; i = li[i].next)
    {
      int to = li[i].to;
      if (li[i].v && note[to] + 1 == note[now])
      {
        int k = sap(to, min(maxf - tot, li[i].v));
        li[i].v -= k;
        tot += k;
        li[li[i].opt].v += k;
        if (note[s] >= n || tot == maxf) return tot;
      }
      if (li[i].v) mi = min(mi, note[to]);
    }
    if (!tot)
    {
      if (!--num[note[now]])
      {
        note[s] = n;
        return 0;
      }
      ++num[note[now] = mi + 1];
    }
    return tot;
  }

  int query(int S, int T)
  {
    s = S, t = T;
    memset(num, 0, sizeof(num));
    memset(note, 0, sizeof(note));
    num[0] = n;
    int ans = 0;
    while (note[s] < n) ans += sap(s, NFinf);
    return ans;
  }

  void clear()
  {
    l = s = t = n = 0;
    memset(be, 0, sizeof(be));
    memset(num, 0, sizeof(num));
    memset(note, 0, sizeof(note));
  }
};

//===========================NetworkFlow===============
