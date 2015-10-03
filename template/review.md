# 分块
* 桶的大小 p = sqrt(n)，块数 q = n / p + (n % p ? 1 : 0)
* 可以预处理 belong[i] = (i - 1) / p - 1
l[i] = (i - 1) * p + 1, r[i] = i * p, r[q] = n


# 二分
* lower_bound 第一个**不小于**
upper_bound 第一个**大于**
* 结构体比较
```cpp
bool cmp(const A &x, const A &y) {
    return x.v < y.v;
}
```

# bitset
* 清零 reset()
* 计数 count()
* 翻转 flip()

# 优先队列
* 结构体比较
```cpp
bool operator<(const thing& rhs) const {
    return a < rhs.a;
}
```

# rope
```cpp
#include <ext/rope>
using __gnu_cxx::crope;
crope rp;
```

# kdtree

# cdq 分治

# 整体二分

# 单调队列
* 利用双端队列实现，在队列中存数组下标。
* 滚动窗口：每次从头弹出不在窗口内的元素，从尾弹出小于新元素的元素，新元素插入到尾。

# 单调栈
* 同样存下标。
* 最大面积：正反扫两遍维护 l, r 数组，表示 h[i] 能向左/右扩展的最大长度。