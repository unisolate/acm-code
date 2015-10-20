/// Hash (Rabin-Karp, RK)，与二分配合使用。应用广泛。(综合白书和图灵白书学习)
/// 题库：http://acm.hust.edu.cn/vjudge/contest/view.action?cid=41757#overview
const ull B = 100000007ULL; /// 哈希基数，1e8 + 7
const int mx_s_num = 105; /// 字符串个数

char s[mx_s_num][mx]; /// 注意，一定要用gets(s[i] + 1)，从下标1开始读
ull ha[mx_s_num][mx], bp[mx] = {1ULL}; /// ha[i]从1开始，一直到ha[i][n]
int len[mx_s_num]; /// len[i] = strlen(s[i] + 1); 一定要是s[i] + 1，否则n会是0

void init_hash(int s_num) { /// 请在main()中完成len的求取。
    int i, j;
    For(i, s_num) Forr(j, 1, len[i] + 1) ha[i][j] = ha[i][j - 1] * B + s[i][j];
    int n = Max(len, s_num); /// 调用#define的Max()
    Forr(i, 1, n + 1) bp[i] = bp[i - 1] * B;
}

ull get_hash(char *s) { /// 直接返回整个字符串的hash
    ull ha = 0ULL;
    for (int i = 0; s[i]; ++i) ha = ha * B + s[i];
    return ha;
}

ull get_hash(int *a, int n) { /// 返回整个int数组的hash值
    int i;
    ull ha = 0ULL;
    For(i, n) ha = ha * B + (ull)a[i];
    return ha;
}

/// 注意pos一定不能是0!!!!
inline ull get_hash(ull *Ha, int pos,
                    int l) { /// 返回Ha[pos...pos+l-1]的值，pos与l必须是正数
    return Ha[pos + l - 1] - Ha[pos - 1] * bp[l];
}

inline ull merge_hash(ull ha1, ull ha2,
                      int len2) { /// 返回s1+s2拼接后的hash值
    return ha1 * bp[len2] + ha2;
}

bool contain(int ida, int
             idb) { /// b是否为a的子串 ，ida和idb为字符串下标，若只有两个字符串，使用时传入参数(0, 1)、(1, 0)就行
    if (len[ida] < len[idb]) return false;
    ull hab = ha[idb][len[idb]];
    for (int i = 1; i + len[idb] <= len[ida]; ++i)
        if (get_hash(ha[ida], i, len[idb]) == hab) return true;
    return false;
}

int overlap(int ida, int
            idb) { /// 求a后缀与b前缀的最长公共子串，ida和idb为字符串下标，若只有两个字符串，使用时传入参数(0, 1)、(1, 0)就行
    int ans = 0, i;
    Forr(i, 1, min(len[ida], len[idb]) + 1)
    if (get_hash(ha[ida], len[ida] - i + 1, i) == get_hash(ha[idb], 1, i)) ans = i;
    // 可在if中加上 && strncmp(s[ida] + len[ida] - i + 1, s[idb] + 1, i) == 0(不过这就失去意义了，还不如双hash)
    return ans;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXL 222
typedef unsigned long long ull;
using namespace std;
const ull B = 100000007ULL;
char s[MAXL];
int len;
ull ha[MAXL], bp[MAXL] = {1ULL};
void hash() {
    ha[0] = s[0];
    for (int i = 1; i < len; ++i)
        ha[i] = ha[i - 1] * B + s[i], bp[i] = bp[i - 1] * B;
}
ull get(int pos, int l) {
    return ha[pos + l - 1] - ha[pos - 1] * bp[l];
}
bool check(int p, int l) {
    return get(p, min(l, len - p - l)) == get(p + l, min(l, len - p - l));
}
int main() {
    int k;
    scanf("%s%d", s, &k);
    len = strlen(s);
    if (k >= len) {
        printf("%d\n", 2 * ((k + len) >> 1));
        return 0;
    }
    hash();
    for (int i = (len + k) >> 1; i >= k; --i) {
        for (int j = 0; j <= len + k - 2 * i; ++j) {
            if (check(j, i)) {
                printf("%d\n", 2 * i);
                return 0;
            }
        }
    }
}

#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXL 222
typedef unsigned long long ull;
using namespace std;
const ull B = 100000007ULL;
char s[MAXL];
int len;
ull ha[MAXL], bp[MAXL] = {1ULL};
void hash() {
    ha[0] = s[0];
    for (int i = 1; i < len; ++i)
        ha[i] = ha[i - 1] * B + s[i], bp[i] = bp[i - 1] * B;
}
ull get(int pos, int l) {
    return ha[pos + l - 1] - ha[pos - 1] * bp[l];
}
bool check(int p, int l) {
    return get(p, min(l, len - p - l)) == get(p + l, min(l, len - p - l));
}
int main() {
    int k;
    scanf("%s%d", s, &k);
    len = strlen(s);
    if (k >= len) {
        printf("%d\n", 2 * ((k + len) >> 1));
        return 0;
    }
    hash();
    for (int i = (len + k) >> 1; i >= k; --i) {
        for (int j = 0; j <= len + k - 2 * i; ++j) {
            if (check(j, i)) {
                printf("%d\n", 2 * i);
                return 0;
            }
        }
    }
}