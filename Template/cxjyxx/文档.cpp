1.  Suffix_Array//后缀数组
2.  Link_Table//链表
3.  Link_Table_V//带权链表
4.  Suffix_Auto_Maton//后缀自动机
5.  KMP//看**
6.  AC_Auto_Maton//AC自动机
7.  Splay//Splay 平衡树
8.  Link_Cut_Tree//动态树
9.  Segment_Tree//线段树
10. Tree_Chain_Division//熟练剖分
11. KD_Tree//kd树
12. Network_Flow//最大流
13. Network_Cost_Flow_Spfa//最小费用最大流 spfa版
14. Network_Cost_Flow_Zkw//最小费用最大流 zkw版
15. Network_Flow_Up_Down//上下界流
16. Network_Cost_Flow_Up_Down//上下界费用流
17. Mergeable_Tree//可并堆
18. Hash_Map//hash
19. Geometry_Base//几何_基本
20. Geometry_Polygon//几何_多边形
21. Geometry_Round//几何_圆
22. Shortest_Path//最短路
23. High_Num//高精
24. Discretization//离散化
25. Tarjan//tarjan

other. par
       point
       range

=========================================================
Suffix_Array

  const int SAmaxn 为字符串最大长度
  const int SAmaxm 为字符串最多字符种数
  
  void create(string) [s] 传入字符串s 建立s的SA
  void clear() 清空SA
=========================================================
Link_Table

  const int LTmaxn 为最大的最大点编号
  const int LTmaxm 为最多边数

  void makeline(int, int) [u, v] 建立u->v的单向边
  void makeline_double(int, int) [u, v] 建立u、v的双向边
  int be(int) [now] 返回now连出的第一条边
  int next(int) [i] 返回i这条边的下一条边
  int to(int) [i]  返回这条边指向的点
  void clear() 清空链表
=========================================================
Link_Table_V

  const int LTmaxn 为最大的最大点编号
  const int LTmaxm 为最多边数

  void makeline(int, int, int) [u, v, va] 建立u->v的权值为va单向边
  void makeline_double(int, int, int) [u, v, va] 建立u->v的权值为va双向边
  int be(int) [now] 返回now连出的第一条边
  int next(int) [i] 返回i这条边的下一条边
  int v(int) [i] 返回i这条边的权值
  int to(int) [i]  返回这条边指向的点
  void clear() 清空链表
=========================================================
Suffix_Auto_Maton

  const int SAMmaxn 为字符从最大长度*2

  void create() 初始化SAM
  void add(char, int) [c, len] 往当前SAM加入字符c len是这个字符在串中的位置 从1开始
  void clear() 清空SAM
=========================================================
KMP

  const int KMPmaxn 为字符串最大长度

  void create(string) [s] 建立s的KMP
  void clear() 清空KMP
=========================================================
AC_Auto_Maton

  const int ACAMmaxn 最多节点数
  const int ACAMmaxm 最多字符种数

  void create(char) [c] 传入最小字符c 如'a' 或 ‘A’
  void add(string) [s] 把该字符串s加入ACAM
  void getfail() 取得ACAM的fail值
  void clear() 清空ACAM
=========================================================
Splay

  const int SPLAYmaxn 最多节点数
  const int SPLAYinf 最大权值abs

  void create() 初始化splay
  void clear(int) [u] 清空节点u
  int lower_bound(int) [k] 返回第一个key不小于k的节点编号
  void insert(int) [k] 插入key为k的节点
  int get_lower(int) [k] 返回k的前驱
  int get_upper(int) [k] 返回k的后继
  void del(int, int) [l, r] 删除key为l~r的所有节点
  int get_kth(int) [k] 返回key值第k小的节点
=========================================================
Link_Cut_Tree
  //这个类内的节点编号和外部的节点边号不一样 一般传入外部编号即可 get_v函数需要传入内部节点编号 to_num函数可以把外部节点转为内部节点编号

  const int LCTmaxn 最大节点数
  
  void create(int, Link_Table, int[]) [n, L, a[]] 表示有n个节点 
                                 连接信息存储在L中 权值信息存储在a[]中
                                 下标为1~n
  void make_root(int) [u] 把节点u转到根
  void link(int, int) [u, v] 连接两个节点u, v
  void cut(int, int) [u, v] 切断两个节点u, v间的连边
  int query_sum(int, int) [u, v] 返回u, v路径上的节点权值和
  int query_max(int, int) [u, v] 返回u, v路径上有最大权值的节点的内部编号
  int query_max(int, int) [u, v] 返回u, v路径上有最小权值的节点的内部编号
  int root(int) [u] 返回节点u所在树的根
  void modify_sum(int, int, int) [u, v, value] 把u到v路径上所有点的权值+value
  void refresh(int) [u] 刷新节点u的信息
  int get_v(int) [u] /*u为内部节点编号*/ 返回内部节点u对应权值
  int to_num(int) [u] 返回外部节点u对应内部节点编号
  void clear() 清空LCT
=========================================================
Segment_Tree

  const int STmaxn 最大节点数 一般为4*n
  const int STinf 最大权值abs

  void create(int, int, int[]) [l, r, a[]] 传入ST的左右范围 和初始权值数组
  void modify_is(int, int, int) [l, r, v] 把l~r的权值都改为v
  void modify_sum(int, int, int) [l, r, v] 把l~r的权值都加v
  int query_max(int, int) [l, r] 返回l~r的最大值
  int query_min(int, int) [l, r] 返回l~r的最小值
  int query_sum(int, int) [l, r] 返回l~r的权值和
  void clear() 清空ST
=========================================================
Tree_Chain_Division
  //这里的树链剖分可以采用两种create方法 一种是边权 一种是点权 后面会介绍 调用这个类的时侯 同时也要调用 Segment_Tree、Link_Table、Link_Table_V

  const int TCDmaxn 最大节点数

  void create(int, Link_Table_V) [n, L] 表示这棵树有n个节点 权值为边权 保证节点1为有效节点 连边关系及权值关系为L
  void create(int, Link_Table, int[]) [n, L, v[]] 表示这棵树有n个节点 权值为点权 保证节点1为有效节点 连边关系为L 点权为v[]
  int lca(int, int) [u, v] 返回节点u, v的lca
  void modify_sum(int, int, int) [u, v, value] 把u到v路径上所有点的权值+value
  void modify_is(int, int, int) [u, v, value] 把u到v路径上所有点的权值改为value
  int query_sum(int, int) [u, v] 返回u, v路径上的节点权值和
  int query_max(int, int) [u, v] 返回u, v路径上有最大权值的节点的内部编号
  int query_max(int, int) [u, v] 返回u, v路径上有最小权值的节点的内部编号
  void clear() 清空TCD  
=========================================================
KD_Tree
  
  KDT_Point
    xy[KDTmaxp] 点坐标
    num 点编号
    dist 内部使用 无需理解

  const int KDTmaxp 最大维度
  const int KDTmaxn 最大节点数
  const int KDTinf 最大dist值

  void create(int, KDT_Point[], int) [n, k[], p] 表示一共有n个节点要预先建树 节点信息存在k[]里 下标0~n-1 维度为p
  void insert(KDT_Point) [k] 往KD_Tree里插入节点k
  void query_max(KDT_Point, *KDT_Point[], int) [a, &ans[], k] 返回离点a的k远点 写在ans[]里  
  void query_min(KDT_Point, *KDT_Point[], int) [a, &ans[], k] 返回离点a的k近点 写在ans[]里
  int dist(KDT_Point, KDT_Point) [a, b] 返回点a、b的距离
  void clear() 清空KDT
=========================================================
Network_Flow

  const int NFmaxn 最大节点数
  const int NFmaxm 最大边数
  const int NFinf 最大权值

  void create(int) [n] 一共有n个点
  void makeline(int, int, int) [u, v, va] 建立u->v权值为va的边 会建立反向边
  int query(int, int) [s, t] 以s为源点 以t为汇点 跑最大流 返回流量
  void clear() 清空NF
=========================================================
Network_Cost_Flow_Spfa
//需调用par类

  const int NCFSmaxn 最大节点数
  const int NCFSmaxm 最大边数
  const int NCFSinf_ 最大权值的两位 如(0x7f)
  const int NCFSinf 最大权值必为NCFSinf_的满状态 如（0x7f7f7f7f)

  void create() 无意义
  void makeline(int, int, int, int) [u, v, va, c] 建立u->v权值为va 费用为c的边 会建立反向边
  par query(int, int) [s, t] 以s为源点 以t为汇点 跑最小费用最大流 返回(最大流量, 最小费用)
  void clear() 清空NCFS
=========================================================
Network_Cost_Flow_Zkw
//需调用par类

  const int NCFZmaxn 最大节点数
  const int NCFZmaxm 最大边数
  const int NCFSinf_ 最大权值的两位 如(0x7f)
  const int NCFSinf 最大权值必为NCFSinf_的满状态 如（0x7f7f7f7f)

  void create() 无意义
  void makeline(int, int, int, int) [u, v, va, c] 建立u->v权值为va 费用为c的边 会建立反向边
  par query(int, int) [s, t] 以s为源点 以t为汇点 跑最小费用最大流 返回(最大流量, 最小费用)
  void clear() 清空NCFZ
=========================================================
Network_Flow_Up_Down
//需调用Network_Flow类

  NFUDinf 最大权值

  void create(int, int, int, int, int) [n, s, t, ss, tt] n个点 源为s 汇为t 超级源为ss 超级汇为tt 只要保证ss和tt不会被用到即可
  void makeline(int, int, int, int, int) [u, v, down, up] 建立从u到v的 流量上界为up 下界为down的边 会建立反向边
  int query() 返回最大流量 如果无解 返回-1 注意 这个函数建议只调用一次 和不带上下界的不一样
  void clear() 清空NFUD
=========================================================
Network_Cost_Flow_Up_Down
//需调用Network_Cost_Flow_Zkw、par类

  NCFUDinf 最大权值

  void create(int, int, int, int) [s, t, ss, tt] 源为s 汇为t 超级源为ss 超级汇为tt 只要保证ss和tt不会被用到即可
  void makeline(int, int, int, int, int, int) [u, v, down, up, c] 建立从u到v的 流量上界为up 下界为down 费用为c的边 会建立反向边
  par query() 返回(最大流量, 最小费用) 如果无解 返回(-1, -1) 注意 这个函数建议只调用一次 和不带上下界的不一样
  void clear() 清空NCFUD
=========================================================
Mergeable_Tree
//可并堆 大根堆

  MHmaxn 最大节点数
  
  void create() 无意义
  int merge(int, int) [u, v] 合并以u,v为根的两个堆 返回新的根
  int make_node(int) [v] 建立一个只有一个元素 元素权值为v的堆 返回根的编号
  int pop(int) [u] 删除以u为根的堆的根 返回新根
  int top(int) [u] 返回以u为根的堆的根的权值
  void clear() 清空MT
=========================================================
Hash_Map

  HMmaxn 最多元素数

  HM_Member_V 存放需保存的值的类
  HM_Member 存放须hash的值和对应权值类

  MOD 模数
  MOD2 hash用的乘数
  
  void create() 无意义
  int hash(HM_Member&) [a] 返回a的hash值 可能需要重载
  bool check(HM_Member&) [a] 返回a是否出现在hash表中
  HM_Member_V get(HM_Member&) [a] 返回a对应的权值类 默认a出现在hash表中
  void insert(HM_Member&) [a] 把a插入hash表中 如果a已经出现在hash表中 会把原来a的权值类更新为新的a的权值类 否则直接插入
  void clear() 清空HM
=========================================================
Geometry_Base

  eps 误差保留
  pi π
  
  point 存放一个点
  {
	double x, y坐标
	
	point (double, double) 构造函数
	point +(point, point) 向量加
	point -(point, point) 向量减
	point *(point, point) 向量乘
	point /(point, point) 向量除
	double &(point, point) 叉乘
	double |(point, point) 点乘
	point +=(point) 向量加
	point -=(point) 向量减
	point *=(double) [a] x、y都乘a
	point /=(double) [a] x、y都除a
	point ==(point, point) [a, b] 返回（a、b是同一个点）
	point !=(point, point) [a, b] 返回（a、b不是同一个点）
	point <(point, point) [a, b] 如果(a.x < b.x) 或 (a.x == b.x 且 a.y < b.y) 就返回true 否则返回false
  }
  
  segment 存放一个线段
  {
	point a, b 线段两个端点
	
	segment(point, point) 构造函数
	point ==(point, point) [a, b] 返回（a、b是同一线段）
	point !=(point, point) [a, b] 返回（a、b是不同一线段）
  }
  
  void create() 无意义
  double sqr(double) [a] 返回a * a
  point rotate(point, double) [a, b] 把a作为向量 顺时针旋转b(弧度制)
  segment get_vertical(segment, point) [a, b] 返回点b关于直线a的垂线
  point get_foot(segment, point) [a, b] 求出点b对于直线a的垂足
  point get_mid(segment) [a] 求线段a的中点
  double dist(point, point) [a, b] 返回a、b两点的距离
  double dist(segment, point) [a, b] 返回点b与直线a的距离(注意这里是直线)
  double dist2(segment, point) [a, b] 返回点b与线段a的距离(注意这里是线段)
  int cmp(double, double) [a, b] 返回在eps下 a、b的大小关系 (0 =) (-1 <) (1 >)
  int pos(point, point) [p, q] 把p、q作为向量 返回q关于p的位置关系 (0 平行) (-1 q在p右侧) (1 q在p左侧)
  int pos(segment, segment) [p, q] 返回两条线段作为向量的q关于p的位置关系(由线段的a点指向b点) 返回值同上
  int pos(segment, point) [p, q] 返回点q关于作为向量的线段p的位置关系 返回值同上
  bool init(segment, point) [a, b] 判断点b是否在线段a内
  int check(segment, segment) [a, b] 判断线段a、b是否相交 （0 无交点） (-1 平行相交<可能无数交点>) (1 一个交点)
  point cross(segment, segment) [a, b] 返回a、b作为直线的交点 如果平行返回(0, 0)
  double get_k(segment) [s] 返回s的斜率 如果k垂直x轴 返回0
  double get_b(segment) [s] 返回s的截距 如果k垂直x轴 返回0
  void clear() 无意义
  
  typedef Geometry_Base::point gbp; 声明Geometry_Base::point类型可以用GBP 构造函数同理
  typedef Geometry_Base::segment gbs; 声明Geometry_Base::segment类型可以用GBS 构造函数同理  
=========================================================
Geometry_Polygon
//需调用Geometry_Base类

  GPmaxn 表示最大顶点数
  
  int n 记录顶点数
  int a[] 记录顶点
  
  void create(int, vector<gbp>) [n, a] 建立有n个顶点 分别是a的多边形
  double get_s() 返回多边形面积
  int check(gbp) [a] 返回a是否在多边形内 (-1 边界) (0 外部) (1 内部)
  double get_in_len(gbs) 返回某条线段被多边形覆盖的长度
  void clear() 清除多边形
=========================================================
Geometry_Round
//需调用Geometry_Base类

  void create(gbp, double) [o, r] 建立圆心为o 半径为r的圆
  int check(gbp) [a] 返回a是否在圆内 (-1 边界) (0 外部) (1 内部)
  int check(gbs) [s] 返回直线s与圆的交点个数
  int check2(gbs) [s] 返回线段s与圆的交点个数
  vector<gbp> cross(gbs) [s] 返回直线s与圆的交点集合
=========================================================
Shortest_Path
//需调用Link_Table_V类
//堆优化的dij实现

  SPmaxn 最大点数
  
  int query(Link_Table_V, int, int) [l, s, t] 返回在l图上 s到t的最短路 如果不联通 返回-1
=========================================================
High_Num

  cut 压缩的位数
  HNmaxn 最大位数/cut
  
  create(int a) [a] 新建值为a的高精数
  create(string a) [a] 新建值为a的高精数 第一个字符如果为'-'则为负数 否则为正 其他字符必须为'0'~'9'
  {
    +
    -
    *
    /
	%
	+=
	-=
	*=
	/=
	%=
	=
	==
	!=
	<
	>
	<=
	>=
	对于两个High_Num间的 或 一个High_Num和一个int间的 以上操作符 均支持
  }
  int to_int() 返回这个高精数的int形 爆了自重
  print() 输出高精数
  clear() 清空高精数
=========================================================
Discretization
//要引用functional库

  Dmaxn 最大需离散成员数
  
  Discretization<class T> a; 声明一个为T类型进行离散的离散化类的实例a
  
  int sau(T*, int, class, class) [a, n, _less = less<class>(), _equal = equal_to<class>()] 对T类型的a数组的前n位(下标从0开始)进行排序并去重 返回去重后n的大小 注意这里是直接在传入的数组上进行改变 后两个参数是比较函数 跟sort传入的比较函数一样 这两个函数为bool类型 都需有两个T类型参数 第一个函数返回第一个参数是否小于第二个参数 第二个函数返回第一个参数是否等于第二个参数
  
  void query(T*, int, int*, class, class) [a, n, ans, _less = less<class>(), _equal = equal_to<class>()] 对a数组的前n位进行离散化 结果存入ans数组中 后两个参数同上
  
  实例：
  //------------0--------------
  #include <iostream>
  #include <cstdio>
  #include <functional>
  /*
	Discretization类
  */
  Discretization<int> D;
  
  int n, ans[100], a[100];
  
  int main()
  {
	READ(a, n); //对a进行读入 这里不实现 下同
	D.query(a, n, ans); //缺省
	n = D.sau(a, n); //缺省  注意这里调用的两个函数是不相关的 只是为了演示如何使用 下同
  }    
  //------------0--------------
  //------------1--------------
  #include <iostream>
  #include <cstdio>
  #include <functional>
  /*
	Discretization类
  */
  struct point
  {
	int a, b;
  };
  
  bool _less(point a, point b)
  {
	return a.a < b.a;
  }
  
  bool _same(point a, point b)
  {
	return a.b < b.b;
  }
  
  Discretization<point> D;
  point a[100];
  int n, ans[100];
  
  int main()
  {
	READ(a, n);
	D.query(a, n, ans, _less, _same);
	n = D.sau(a, n, _less, _same);
  }
  //------------1--------------
  //------------2--------------
  #include <iostream>
  #include <cstdio>
  #include <functional>
  /*
	Discretization类
  */
  Discretization<double> D;

  bool same(double a, double b)
  {
    return abs(a - b) <= 1e-8;
  }
  
  double a[100];
  int n, ans[100];
  
  int main()
  {
	READ(a, n);
	D.query(a, n, ans, less<double>(), same); //这里的less是functional自带的函数 可以直接这样使用
	n = D.sau(a, n, less<double>(), _same); //同上
  }  
  //------------2--------------
=========================================================
Tarjan
//需调用Link_Table类

  Tmaxn 最大点数
  Tmaxm 最大边数 注意 如果是双向边要乘2
  
  void get_cut_node(Link_Table, int, int*) [L, n, b] 在L这张图上 共有n个点(编号为0~n-1 如果有些编号没点没关系) 在b数组中 b[i]==true 表示点i为割点 否则不是 注意b数组下标大于n - 1 的数值不确定
  void get_cut_edge(Link_Table, int, int*) [L, n, b] 在L这张图上 共有n个点(同上) 在b数组中 b[i]==true 表示L中的下标为i的边为割边(由于Link_Table中是有向边 一条割边将有两条对应边被记为割边) 注意b数组下标大于n - 1 的数值不确定
=========================================================