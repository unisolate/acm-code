//===========================AC_AutoMaton==============

const int ACAMmaxn = 500005;
const int ACAMmaxm = 30;

struct ACAM_Node
{
  int ch[ACAMmaxm], fail;
  int num;
};

struct AC_Auto_Maton
{
  ACAM_Node t[ACAMmaxn];
  int tot, root;
  queue<int> q;
  char base;

  void create(char ba)
  {
    root = tot = 2;
    base = ba;
  }

  void add(string s)
  {
    int n = s.length();
    for (int now = root, i = 0; i < n; ++i)
    {
      if (t[now].ch[s[i] - base]) now = t[now].ch[s[i] - base];
      else t[now].ch[s[i] - base] = ++tot, now = tot;
      if (i == n - 1) ++t[now].num;
    }
  }

  void get_fail()
  {
    q.push(root);
    while (!q.empty())
    {
      int now = q.front();
      q.pop();
      for (int i = 0; i < 26; ++i)
      {
        int to = t[now].ch[i];
        if (!to) continue;
        if (now == root) t[to].fail = root;
        else
        {
          int k;
          for (k = t[now].fail; k != root && !t[k].ch[i]; k = t[k].fail);
          if (t[k].ch[i]) k = t[k].ch[i];
          t[to].fail = k;
        }
        q.push(to);
      }
    }
  }

  void clear()
  {
    memset(t, 0, sizeof(t));
    tot = 0;
  }
};

//===========================AC_AutoMaton==============
