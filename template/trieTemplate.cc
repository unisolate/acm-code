/*==================================================*\
  [Trie] 字典树
  support:
        - insert O(L)
        - query O(L)
        - delete O(L)
  Trie[i]存储第i个节点的信息:
        next[j]: 下一个字符为j时 对应的节点编号
        fa: 父亲节点编号
        cnt: 字符出现次数
\*==================================================*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;
//----------------------------------------------
#define CL(a,num) memset(a,num,sizeof(a));
#define BtoA(x,y) memcpy(x,y,sizeof(x));
#define eps  1e-12
#define inf  0x7fffffff
typedef    __int64    LL;
//----------------------------------------------
const int Node_max = 100000 + 5;

struct Node
{
    int next[26];
    // including a...z
    int fa, cnt, flag;
} Trie[Node_max];
// root = Trie[0]
int Trie_size;
#define t_s Trie_size

int Trie_ins(char str[])
{
    int len = strlen(str);
    int tmp = 0;
    for (int i = 0; i < len; ++i)
    {
        if (!Trie[tmp].next[str[i] - 'a'])
        {
            Trie[tmp].next[str[i] - 'a'] = ++t_s;
            Trie[t_s].fa = tmp;
        }
        tmp = Trie[tmp].next[str[i] - 'a'];
    }
    return ++Trie[tmp].cnt;
    // let the appear_times of str increase then return it
}
int Trie_query(char str[])
{
    //return the appear_times of str
    int len = strlen(str);
    int tmp = 0;
    for (int i = 0; i < len; ++i)
    {
        if (!Trie[tmp].next[str[i] - 'a'])
            return -1;    // if can't find str
        tmp = Trie[tmp].next[str[i] - 'a'];
    }
    return Trie[tmp].cnt;
}
int Trie_del(char str[])
{
    int len = strlen(str);
    int tmp = 0;
    for (int i = 0; i < len; ++i)
    {
        if (!Trie[tmp].next[str[i] - 'a'])
            return -1; // if can't find str
        tmp = Trie[tmp].next[str[i] - 'a'];
    }
    return --Trie[tmp].cnt;
    // let the appear_times of str decrease then return it
}
int main()
{
    char str[20];
    while (true)
    {
        int op;
        cin >> op;
        switch (op)
        {
        case 0: //ins
            cin >> str;
            cout << Trie_ins(str) << endl;
            break;
        case 1: //query
            cin >> str;
            cout << Trie_query(str) << endl;
            break;
        case 2: //del
            cin >> str;
            cout << Trie_del(str) << endl;
            break;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxnode = 4000 * 100 + 5; /// trie树节点上限 = maxw * maxwl
const int sigma_size = 26;
const int maxl = 300000 + 5; /// 文本串最大长度
const int maxw = 4000 + 5;   /// 单词最大个数
const int maxwl = 100 + 5;   /// 每个单词最大长度
const int MOD = 20071027;

struct Trie
{
    int ch[maxnode][sigma_size]; /// ch[node_id][nextchar]表示第id号节点下的节点对应的id号
    int val[maxnode];
    int sz; /// 结点总数
    void clear()
    {
        sz = 1;    /// 初始时只有一个根结点
        memset(ch[0], 0, sizeof(ch[0]));
    }

    /// 插入字符串s，附加信息为v。注意v必须非0，因为0代表“本结点不是单词结点”
    void insert(const char *s, int v)
    {
        int u = 0, n = strlen(s), c;
        for (int i = 0; i < n; ++i)
        {
            c = s[i] - 'a';
            if (ch[u][c] == 0)  /// 结点不存在
            {
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 0;  /// 中间结点的附加信息为0
                ch[u][c] = sz++; /// 新建结点
            }
            u = ch[u][c]; /// 往下走
        }
        val[u] = v; /// 字符串的最后一个字符的附加信息为v
    }

    /// 找字符串s的前缀(前缀长度<=len)
    void find_prefixes(const char *s, int len, vector<int> &ans)
    {
        int u = 0, c;
        for (int i = 0; s[i] && i < len; ++i)
        {
            c = s[i] - 'a';
            if (ch[u][c] == 0) break;
            u = ch[u][c];
            if (val[u]) ans.push_back(val[u]); /// 找到一个前缀
        }
    }
} trie;