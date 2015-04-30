//===========================Discretization============

template<typename T>
struct Discretization
{
    static const int Dmaxn = 1005;
    T t[Dmaxn];
    int sau(T *a, int n)
    {
        sort(a, a + n, less<T>());
        return unique(a, a + n, equal_to<T>()) - a;
    }
    void query(T *a, int n, int *ans)
    {
        for (int i = 0; i < n; ++i)
            t[i] = a[i];
        sort(t, t + n, less<T>());
        int m = unique(t, t + n, equal_to<T>()) - t;
        for (int i = 0; i < n; ++i)
            ans[i] = lower_bound(t, t + m, a[i], less<T>()) - t;
    }
    template<typename _compare, typename __compare>
    int sau(T *a, int n, _compare _less, __compare equal)
    {
        sort(a, a + n, _less);
        return unique(a, a + n, equal) - a;
    }
    template<typename _compare, typename __compare>
    void query(T *a, int n, int *ans, _compare _less = less<T>(), __compare equal = equal_to<T>())
    {
        for (int i = 0; i < n; ++i)
            t[i] = a[i];
        sort(t, t + n, _less);
        int m = unique(t, t + n, equal) - t;
        for (int i = 0; i < n; ++i)
            ans[i] = lower_bound(t, t + m, a[i], _less) - t;
    }
};

//===========================Discretization============