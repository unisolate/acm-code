//===========================SAM=======================

const int SAMmaxn = 500005;

struct SAM_Node
{
  int ch[30], fail, l;
};

struct Suffix_Auto_Maton
{
  SAM_Node t[SAMmaxn];
  int n, last, tot;

  void add(int c, int l)
  {
    int now = ++tot, p = last;
    last = tot;
    t[now].l = l;
    for (; p && !t[p].ch[c]; p = t[p].fail) t[p].ch[c] = now;
    if (!p) t[now].fail = 1;
    else if (t[p].l + 1 == t[t[p].ch[c]].l) t[now].fail = t[p].ch[c];
    else
    {
      int r = ++tot, k = t[p].ch[c];
      t[r] = t[k];
      t[r].l = t[p].l + 1;
      t[k].fail = t[now].fail = r;
      for (; p && t[p].ch[c] == k; p = t[p].fail) t[p].ch[c] = r;
    }
  }

  void create(string s)
  {
    int n = s.length();
    tot = last = 1;
    for (int i = 0; i < n; ++i) add(s[i] - 'a', i + 1);
  }

  void clear()
  {
    memset(t, 0, sizeof(t));
  }
};

//===========================SAM=======================
