//===========================LinkTable=================

const int LTmaxm = 1000005;
const int LTmaxn = 1000005;

struct line
{
  int to, next;
};

struct Link_Table
{
  line li[LTmaxm];
  int be_[LTmaxn], l;

  int to(int i) { return li[i].to; }
  int next(int i) { return li[i].next; }
  int be(int i) { return be_[i]; }

  void makeline(int fr, int to)
  {
    ++l;
    li[l].next = be_[fr];
    be_[fr] = l;
    li[l].to = to;
  }

  void makeline_double(int fr, int to)
  {
    makeline(fr, to);
    makeline(to, fr);
  }

  void clear()
  {
    l = 0;
    memset(be_, 0, sizeof(be_));
  }
};

//===========================LinkTable=================
