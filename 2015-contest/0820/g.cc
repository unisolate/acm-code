#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAXN = 100001, BLOCK = 1000;
int TestData, n, m, a[MAXN];
int Blocks, BlockSize[BLOCK], BlockArray[BLOCK][BLOCK];

inline int *lower_bound(int *const beg, int *const end, const int x) {
    int *const pos = std::lower_bound(beg, end, x);
    return *pos == x ? std::upper_bound(beg, end, x) - 1 : pos - 1;
}
inline int GetMin() {
    int res = 0x7FFFFFFF;
    for (int i = 0; i < Blocks; ++i)
        res = std::min(res, BlockArray[i][0]);
    return res;
}
inline int GetMax() {
    int res = 0x80000000;
    for (int i = 0; i < Blocks; ++i)
        res = std::max(res, BlockArray[i][BlockSize[i] - 1]);
    return res;
}
int Count(const int st, const int ed, const int x) {
    const int bs = st / BLOCK, be = ed / BLOCK;
    int cnt = 0;
    if (bs == be) {
        for (int i = st; i <= ed; ++i) cnt += a[i] <= x;
        return cnt;
    }
    for (int i = st; i < (bs + 1)*BLOCK; ++i) cnt += a[i] <= x;
    for (int i = be * BLOCK; i <= ed; ++i) cnt += a[i] <= x;
    for (int i = bs + 1; i < be; ++i)
        cnt += lower_bound(BlockArray[i], BlockArray[i] + BlockSize[i],
                           x) - BlockArray[i] + 1;
    return cnt;
}
void Solve() {
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        BlockArray[i / BLOCK][BlockSize[i / BLOCK]++] = a[i];
    }
    scanf("%d", &m);
    Blocks = 1 + (n - 1) / BLOCK;
    for (int i = 0; i < Blocks; ++i)
        std::sort(BlockArray[i], BlockArray[i] + BlockSize[i]);
    for (char c; m--;) {
        scanf("\n%c", &c);
        if (c == '2') {
            int st, ed, k;
            scanf("%d%d%d", &st, &ed, &k);
            --st, --ed;
            int lef = GetMin() - 1, rig = GetMax();
            while (lef + 1 < rig) {
                const int mid = (lef + rig) / 2;
                const int cnt = Count(st, ed, mid);
                if (cnt >= k)
                    rig = mid;
                else
                    lef = mid;
            }
            printf("%d\n", rig);
        } else {
            int index, value;
            scanf("%d%d", &index, &value);
            const int block = (--index) / BLOCK;
            const int pos = std::lower_bound(BlockArray[block],
                                             BlockArray[block] + BlockSize[block], a[index]) - BlockArray[block];
            BlockArray[block][pos] = a[index] = value;
            std::sort(BlockArray[block], BlockArray[block] + BlockSize[block]);
        }
    }
}
int main() {
    // scanf("%d", &TestData);
    while (~scanf("%d",&n)) {
        Solve();
        memset(BlockSize, 0, sizeof(BlockSize[0])*Blocks);
    }
}
