//===========================KMP=======================

const int KMPmaxn = 100005;

struct KMP
{
  int fail[KMPmaxn];

  void create(string s)
  {
    fail[0] = -1;
    int n = s.length();
    for (int i = 1, j = -1; i < n; ++i)
    {
      while (j != -1 && s[j + 1] != s[i]) j = fail[j];
      if (s[j + 1] == s[i]) ++j;
      fail[i] = j;
    }
  }

  void clear()
  {
    memset(fail, 0, sizeof(fail));
  }
};

//===========================KMP=======================
