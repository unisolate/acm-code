//===========================Tarjan====================

struct Tarjan
{
	static const int Tmaxn = 200005;
	static const int Tmaxm = 200005;
	int low[Tmaxn], dfn[Tmaxn], tot, t[Tmaxm];

	int tarjan(int now, int fa, Link_Table &L, bool *b, int tp)
	{
		dfn[now] = ++tot;
		low[now] = dfn[now];
		int sum = 0, lfa = -1, mi = 0x7fffffff;
		for (int i = L.be(now); i; i = L.next(i))
		{
			int to = L.to(i);
			if (to == fa)
			{
				lfa = i;
				continue;
			}
			if (!dfn[to])
			{
				int t = tarjan(to, now, L, b, tp);
				low[now] = min(low[now], low[to]);
				if (tp)
					if (low[to] > dfn[now]) b[i] = b[t] = 1;
				++sum;
				if (low[to] >= dfn[now] && fa != -1) b[now] = 1;
				mi = min(mi, low[to]);
			}
			else low[now] = min(low[now], dfn[to]);
		}
		if (!tp && sum && fa == -1)
			b[now] = sum > 1 ? 1 : 0;
		return lfa;
	}

	void clear()
	{
		memset(low, 0, sizeof(low));
		memset(dfn, 0, sizeof(dfn));
		tot = 0;
	}

	void get_cut_node(Link_Table &L, int n, bool *b)
	{
		clear();
		for (int i = 0; i < n; ++i)
			b[i] = 0;
		for (int i = 0; i < n; ++i)
			if (!dfn[i])
				tarjan(i, -1, L, b, 0);
	}

	void get_cut_edge(Link_Table &L, int n, bool *b)
	{
		clear();
		for (int i = 0; i < n; ++i)
			b[i] = 0;
		for (int i = 0; i < n; ++i)
			if (!dfn[i])
				tarjan(i, -1, L, b, 1);
		for (int i = 0; i < n; ++i)
		{
			for (int j = L.be(i); j; j = L.next(j))
				++t[L.to(j)];
			for (int j = L.be(i); j; j = L.next(j))
				if (t[L.to(j)] > 1)
					b[j] = 0;
			for (int j = L.be(i); j; j = L.next(j))
				--t[L.to(j)];
		}
	}
};

//===========================Tarjan====================