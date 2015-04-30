//===========================MergeableTree=============

const int MHmaxn = 100005;
 
struct MHnode
{
  int l, r, dis, v;
};
 
struct MergeableHeap  //big first
{
  MHnode t[MHmaxn];
  int tot;
   
  void create()
  {

  }

  int merge(int a, int b)
  {
    if (!a) return b;
    if (!b) return a;
    if (t[a].v < t[b].v) swap(a, b);
    t[a].r = merge(t[a].r, b);
    if (t[t[a].l].dis < t[t[a].r].dis) swap(t[a].l, t[a].r);
    t[a].dis = t[t[a].r].dis + 1;
    return a;
  }
   
  int make_node(int v)
  {
    ++tot;
    t[tot].l = t[tot].r = t[tot].dis = 0;
    t[tot].v = v;
    return tot;
  }
   
  int pop(int root)
  {
    return merge(t[root].l, t[root].r);
  }
   
  int top(int root)
  {
    return t[root].v;
  }

  void clear()
  {
    tot = 0;
  }
};

//===========================MergeableTree=============
