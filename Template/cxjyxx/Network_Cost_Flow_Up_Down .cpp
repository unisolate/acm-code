//===========================NetworkCostFlowUpDown=====

const int NCFUDinf  = 0x7f7f7f7f;

struct NCFUD_Line
{
  int fr, to, next, vu, vd, c, opt;
};

struct Network_Cost_Flow_Up_Down
{
  Network_Cost_Flow_Zkw NCFZ;
  int s, t, ss, tt, li, mo, fi;

  void makeline(int fr, int to, int vd, int vu, int c = 0)
  {
    NCFZ.makeline(fr, to, vu - vd, c);
    NCFZ.makeline(ss, to, vd, 0);
    NCFZ.makeline(fr, tt, vd, 0);
    fi += vd;
    mo += vd * c;
  }

  void create(int S, int T, int SS, int TT)
  {
    s = S, t = T, ss = SS, tt = TT;
    NCFZ.create();
    NCFZ.makeline(t, s, NCFUDinf, 0);
    li = NCFZ.l;
  }

  par query()
  {
    par ans, p;
    p = NCFZ.query(ss, tt);
    if (p.a != fi) return par(-1, -1);
    ans.b = mo + p.b;
    ans.a = 0;
    p = NCFZ.query(s, t);
    ans.a += p.a, ans.b += p.b;
    return ans;
  }

  void clear()
  {
    s = t = ss = tt = li = mo = 0;
    NCFZ.clear();
  }
};

//===========================NetworkCostFlowUpDown=====
