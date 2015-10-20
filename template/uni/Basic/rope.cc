#include <ext/rope>
using namespace __gnu_cxx;
int a[1000];
rope<int> x;
rope<int> x(a, a + n);
rope<int> a(x);

x->at(10);
x[10];
x->push_back(x);     // 在末尾添加x
x->insert(pos, x);   // 在pos插入x
x->erase(pos, x);    // 从pos开始删除x个
x->replace(pos, x);  // 从pos开始换成x
x->substr(pos, x);   // 提取pos开始x个
// 一键可持久化，O(1) 的历史版本
his[0] = new rope<char>();
his[i] = new rope<char>(*his[i - 1]);
/*
题意：设计数据结构支持插入删除反转字符串
分析：由于rope的底层实现，insert，erase，get都是logn的
就是翻转不行，不是自己手写的打不了标记啊！
答：同时维护一正一反两个rope……反转即交换两个子串……
区间循环位移？简单，拆成多个子串连起来就好了……
区间a变b b变c c变d …… z变a？ 呃……维护26个rope？
区间和？滚蛋，那是线段树的活
区间kth？sorry，与数值有关的操作rope一概不支持……
*/