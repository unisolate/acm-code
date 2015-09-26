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
crope rp;s
```

# kdtree

# cdq 分治

# 整体二分