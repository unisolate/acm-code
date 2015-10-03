//===========================SA========================

const int SAmaxn = 100005;
const int SAmaxm = 100005;
struct Suffix_Array
{
  int sa[SAmaxn], sa_t[SAmaxn], t[SAmaxn], v[SAmaxn], v_t[SAmaxn], s[SAmaxn], rank[SAmaxn], h[SAmaxn], cnt[SAmaxm], m, n;

  bool same(int a, int b, int c) { return t[a] == t[b] && t[a + c] == t[b + c]; }

  void geth()
  {
    for (int i = 0; i < n; ++i) rank[sa[i]] = i;
    for (int i = 0, k = 0; i < n; h[rank[i++]] = k)
      if (rank[i])
        for (k = k ? k - 1 : k; s[i + k] == s[sa[rank[i] - 1] + k]; ++k);
      else k = 0;
  }

  void getsa()
  {
    for (int i = 0; i < n; ++i) ++cnt[v[i] = s[i]];
    for (int i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; --i) sa[--cnt[v[i]]] = i;
    for (int j = 1, p = 0, i; p < n; m = p, j <<= 1)
    {
      for (p = 0, i = n - j; i < n; ++i) sa_t[p++] = i;
      for (i = 0; i < n; ++i) if (sa[i] >= j) sa_t[p++] = sa[i] - j;
      for (i = 0; i < m; ++i) cnt[i] = 0;
      for (i = 0; i < n; ++i) ++cnt[v_t[i] = v[sa_t[i]]];
      for (i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
      for (i = n - 1; i >= 0; --i) sa[--cnt[v_t[i]]] = sa_t[i], t[i] = v[i];
      for (i = 1, p = 1, v[sa[0]] = 0; i < n; ++i)
        v[sa[i]] = same(sa[i], sa[i - 1], j) ? p - 1 : p++;
    }
  }

  void create(int s_t[], int n_t, int m_t)
  {
    n = n_t;
    m = m_t;
    for (int i = 0; i < n; ++i) s[i] = s_t[i];
    getsa();
    geth();
  }

  void create(string s_t)
  {
    n = s_t.length();
    m = 300;
    for (int i = 0; i < n; ++i) s[i] = s_t[i];
    getsa();
    geth();
  }

  void clear()
  {
    memset(cnt, 0, sizeof(cnt));
  }
};

//===========================SA========================
