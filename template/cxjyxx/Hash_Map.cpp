//===========================HashMap===================

const int HMmaxn = 1000000;

struct HM_Member_V
{
  int v;
};

struct HM_Member
{
  int n, a[20];
  HM_Member_V v;
};

struct HM_Line
{
  int next;
  HM_Member to;
};

struct Hash_Map
{
  static const int MOD = 19961107;
  static const int MOD2 = 1234567891;
  HM_Line li[HMmaxn];
  int be[MOD], l;
  
  void create()
  {

  }

  int hash(const HM_Member& a)
  {
    int ans = a.n;
    for (int i = 0; i < a.n; ++i)
      ans = (((ll)ans) * MOD2 + a.a[i]) % MOD;
    return ans;
  }

  void makeline(int fr, const HM_Member& to)
  {
    ++l;
    li[l].next = be[fr];
    be[fr] = l;
    li[l].to = to;
  }

  bool same(const HM_Member& a, const HM_Member& b)
  {
    bool br = a.n == b.n;
    for (int i = 0; i < a.n; ++i)
      if (a.a[i] != b.a[i])
      {
        br = false;
        break;
      }
    return br;
  }

  bool check(const HM_Member& a)
  {
    int h = hash(a);
    for (int i = be[h]; i; i = li[i].next)
      if (same(li[i].to, a))
        return true;
    return false;
  }

  HM_Member_V get(const HM_Member& a)
  {
    int h = hash(a);
    for (int i = be[h]; i; i = li[i].next)
      if (same(li[i].to, a))
        return li[i].to.v;
    HM_Member_V k;
    return k;
  }

  void insert(const HM_Member& a)
  {
    int h = hash(a);
    if (check(a))
    {
      for (int i = be[h]; i; i = li[i].next)
        if (same(li[i].to, a))
          {
            li[i].to.v = a.v;
            break;
          }
    }
    else makeline(h, a);
  }

  void clear()
  {
    l = 0;
    memset(be, 0, sizeof(be));
  }
};

//===========================HashMap===================
