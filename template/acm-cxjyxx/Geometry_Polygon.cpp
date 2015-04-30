//===========================Geometry_Polygon==========

struct Geometry_Polygon
{
	static const int GPmaxn = 1005;
	Geometry_Base gb;
	int n;
	gbp a[GPmaxn], mx, t[GPmaxn + 10];
	void create(int _n, vector<gbp> _a)
	{
		n = _n;
		mx = _a[0];
		for (int i = 0; i < n; ++i)
		{
			a[i] = _a[i];
			mx.x = max(mx.x, a[i].x);
			mx.y = max(mx.y, a[i].y);
		}
	}

	void clear()
	{
		n = 0;
	}

	double get_s()
	{
		double ans = a[n - 1] & a[0];
		for (int i = 1; i < n; ++i)
			ans += a[i - 1] & a[i];
		return abs(ans);
	}

	int check(gbp p) //0外部 -1边界 1内部
	{
		if (gb.init(gbs(a[n - 1], a[0]), p)) return -1;
		for (int i = 1; i < n; ++i)
			if (gb.init(gbs(a[i - 1], a[i]), p))
				return -1;
		gbs s = gbs(p, mx + gbp(rand(), rand()));
		int ans = gb.check(s, gbs(a[n - 1], a[0])) ? 1 : 0;
		for (int i = 1; i < n; ++i)
			ans += gb.check(s, gbs(a[i - 1], a[i])) ? 1 : 0;
		return (ans & 1) ? 1 : 0;
	}

	double get_in_len(gbs s)
	{
		int tot = 0;
		t[tot++] = s.a, t[tot++] = s.b;
		if (gb.check(s, gbs(a[n - 1], a[0])) == 1)
			t[tot++] = gb.cross(s, gbs(a[n - 1], a[0]));

		if (gb.init(s, a[0])) t[tot++] = a[0];
		for (int i = 1; i < n; ++i)
		{
			if (gb.init(s, a[i])) t[tot++] = a[i];
			if (gb.check(s, gbs(a[i - 1], a[i])) == 1)
				t[tot++] = gb.cross(s, gbs(a[i - 1], a[i]));
		}
		sort(t, t + tot);
		tot = unique(t, t + tot) - t;
		double ans = 0;
		for (int i = 0; i < tot - 1; ++i)
			if (check(gb.get_mid(gbs(t[i], t[i + 1]))))
				ans += gb.dist(t[i], t[i + 1]);
		return ans;
	}
	
	vector<gbp> get_convex_hull()
	{
		vector<gbp> ans;
		sort(a, a + n);
		ans.push_back(a[0]);
		for (int i = 1; i < n; ++i)
		{
			while (ans.size() > 1 && gb.pos(ans.back() - ans[ans.size() - 2], a[i] - ans[ans.size() - 2]) >= 0) 
				ans.pop_back();
			ans.push_back(a[i]);
		}
		int p = ans.size();
		for (int i = n - 2; i >= 0; --i)
		{
			while (ans.size() > p + 1 && gb.pos(ans.back() - ans[ans.size() - 2], a[i] - ans[ans.size() - 2]) >= 0) 
				ans.pop_back();
			ans.push_back(a[i]);
		}
		ans.pop_back();
		return ans;
	}
};

//===========================Geometry_Polygon==========
