//===========================NetworkFlowUpDown=========

const int NFUDinf  = 0x7f7f7f7f;

struct NFUD_Line
{
  int fr, to, next, vu, vd, c, opt;
};

struct Network_Flow_Up_Down
{
  Network_Flow NF;
  int s, t, ss, tt, li, fi;

  void makeline(int fr, int to, int vd, int vu)
  {
    NF.makeline(fr, to, vu - vd);
    NF.makeline(ss, to, vd);
    NF.makeline(fr, tt, vd);
    fi += vd;
  }

  void create(int n, int S, int T, int SS, int TT)
  {
    s = S, t = T, ss = SS, tt = TT;
    NF.create(n);
    NF.makeline(t, s, NFUDinf);
    li = NF.l;
  }

  int query()
  {
    int ans = 0, p;
    p = NF.query(ss, tt);
    if (p != fi) return -1;
    p = NF.query(s, t);
    ans += p;
    return ans;
  }

  void clear()
  {
    s = t = ss = tt = li = 0;
    NF.clear();
  }
};

//===========================NetworkFlowUpDown=========
