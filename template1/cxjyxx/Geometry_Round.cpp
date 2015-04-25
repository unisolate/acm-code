//===========================Geometry_Round============

struct Geometry_Round
{
	gbp o;
	double r;
	Geometry_Base gb;

	void create(gbp _o, double _r)
	{
		o = _o;
		r = _r;
	};

	int check(gbp p) //里1 边界-1 外0
	{
		int k = gb.cmp(gb.dist(p, o), r);
		if (k == -1) return 1;
		else
		if (k == 0) return -1;
		else return 0;
	}

	int check2(gbs s)
	{
		vector<gbp> v;
		v = cross(s);
		int ans = 0;
		for (int i = 0; i < (int)v.size(); ++i)
			if (gb.init(s, v[i]))
				++ans;
		return ans;
	}

	int check(gbs s)
	{
		int k = check(gb.get_foot(s, o));
		if (k == -1) return 1;
		else
		if (k == 0) return 0;
		else return 2;
	}

	vector<gbp> cross(gbs s)
	{
		vector<gbp> v;
		int c = check(s);
		if (c == 0) return v;
		if (c == 1)
		{
			v.push_back(gb.get_foot(s, o));
			return v;
		}
		s.a -= o, s.b -= o;
		if (!gb.cmp(s.a.x, s.b.x))
		{
			v.push_back(gbp(s.a.x, sqrt(r * r - s.a.x * s.a.x)) + o);
			v.push_back(gbp(s.a.x, -sqrt(r * r - s.a.x * s.a.x)) + o);
			return v;
		}
		else
		{
			double k = gb.get_k(s), b = gb.get_b(s),
						 oo = 1 + k * k, p = 2 * k * b, q = b * b - r * r,
						 delta = sqrt(p * p - 4 * oo * q);
			double x = (-p + delta) / 2 * oo, y = k * x + b;
			v.push_back(gbp(x, y) + o);
			x = (-p - delta) / 2 * oo, y = k * x + b;
			v.push_back(gbp(x, y) + o);
			return v;
		}
		return v;
	}
};

//===========================Geometry_Round============