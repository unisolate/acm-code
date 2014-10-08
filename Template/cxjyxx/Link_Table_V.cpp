//===========================LinkTable_V===============
 
const int LTVmaxm = 200005;
const int LTVmaxn = 200005;
 
struct LTVline
{
  int to, next, v;
};
 
struct Link_Table_V
{
  LTVline li[LTVmaxm];
  int be_[LTVmaxn], l;
 
  int next(int i) { return li[i].next; }
  int be(int i) { return be_[i]; }
  int to(int i) { return li[i].to; }
  int v(int i) { return li[i].v; }
 
  void makeline(int fr, int to, int v)
  {
    ++l;
    li[l].next = be_[fr];
    be_[fr] = l;
    li[l].to = to;
    li[l].v = v;
  }
   
  void makeline_double(int fr, int to, int v)
  {
    makeline(fr, to, v);
    makeline(to, fr, v);  
  }
 
  void clear()
  {
    l = 0;
    memset(be_, 0, sizeof(be_));
  }
};
 
//===========================LinkTable_V===============
