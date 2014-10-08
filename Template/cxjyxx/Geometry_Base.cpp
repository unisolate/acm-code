//===========================Geometry_Base=============

struct Geometry_Base
{
	public:

	static const double eps = 1e-8;
	double pi;

	struct point
	{
		double x, y;

		point() {}
		point(double _x, double _y) : x(_x), y(_y) {}

		point operator-(point a) { return point(x - a.x, y - a.y); }
		point operator+(point a) { return point(x + a.x, y + a.y); }
		point operator*(double a) { return point(x * a, y * a); }
		point operator/(double a) { return point(x / a, y / a); }
		double operator&(point a) { return x * a.y - y * a.x; }
		double operator|(point a) { return x * a.x + y * a.y; }

		bool operator==(point a) { return !cmp(x, a.x) && !cmp(y, a.y); }
		bool operator!=(point a) { return !(!cmp(x, a.x) && !cmp(y, a.y)); }
		bool operator<(point a) const { return cmp(x, a.x) == -1 || (cmp(x, a.x) == 0 && cmp(y, a.y) == -1); }
		
		point operator-=(point a) { x -= a.x, y -= a.y; return *this; }
		point operator+=(point a) { x += a.x, y += a.y; return *this; }
		point operator*=(double a) { x *= a, y *= a; return *this; }
		point operator/=(double a) { x /= a, y /= a; return *this; }
	};

	struct segment
	{
		point a, b;
		segment() {};
		segment(point _a, point _b) : a(_a), b(_b) {};
		bool operator==(segment A) { return (a == A.a && b == A.b) || (b == A.a && a == A.b); }
		bool operator!=(segment A) { return !((a == A.a && b == A.b) || (b == A.a && a == A.b)); }
	};

	Geometry_Base() { pi = acos(-1.); }
	void create() {}
	double sqr(double a) { return a * a; }

	point rotate(point a, double b) {	return point(a.x * cos(b) - a.y * sin(b), a.x * sin(b) + a.y * cos(b)); }
	double dist(point a, point b) { return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y)); }
	static int cmp(double a, double b) { return abs(a - b) < eps ? 0 : (a < b ? -1 : 1); } // (0 =) (-1 <) (1 >)
	int pos(point a, point b) { return cmp(a & b, 0); } // (0 =) (-1 right) (1 left)
	int pos(segment a, segment b) { return pos(a.b - a.a, b.b - b.a); } // (0 =) (-1 right) (1 left)
	int pos(segment a, point b) { return pos(a, segment(a.a, b)); } // (0 =) (-1 right) (1 left)
	bool init(segment a, point b)	{	return !cmp(dist(a.a, a.b), dist(a.a, b) + dist(a.b, b));	}
	segment get_vertical(segment a, point b) { return segment(b, b + rotate(a.b - a.a, pi / 2)); }
	point get_foot(segment a, point b) { return cross(a, get_vertical(a, b));	}
	point get_mid(segment a) { return (a.a + a.b) / 2; }
	double dist(segment a, point b)	{	return dist(get_foot(a, b), b); }
	double dist2(segment a, point b) { point p = get_foot(a, b); return init(a, p) ? dist(p, b) : min(dist(a.a, b), dist(a.b, b)); }

	int check(segment a, segment b)
	{
		if (pos(a, b) == 0)
		{
			if (pos(a, b.a)) return 0;
			if (!cmp(a.a.x, a.b.x))
			{
				if (a.a.y > a.b.y) swap(a.a, a.b);
				if (b.a.y > b.b.y) swap(b.a, b.b);
				if (a.a.y > b.a.y) swap(a, b);
				return cmp(a.b.y, b.a.y) >= 0 ? -1 : 0;
			}
			else
			{
				if (a.a.x > a.b.x) swap(a.a, a.b);
				if (b.a.x > b.b.x) swap(b.a, b.b);
				if (a.a.x > b.a.x) swap(a, b);
				return cmp(a.b.x, b.a.x) >= 0 ? -1 : 0;
			}
		}
		return pos(a, b.a) * pos(a, b.b) <= 0 && pos(b, a.a) * pos(b, a.b) <= 0 ? 1 : 0;
	}

	double get_k(segment a)
	{
		if (!cmp(a.a.x, a.b.x)) return 0;
		return (a.b.y - a.a.y) / (a.b.x - a.a.x);
	}

	double get_b(segment a)
	{
		if (!cmp(a.a.x, a.b.x)) return 0;
		return a.a.y - a.a.x * get_k(a);
	}

	point cross(segment a, segment b)
	{
		if (!pos(a, b)) return point(0, 0);
		if (!cmp(b.a.x, b.b.x)) swap(a, b);
		if (!cmp(a.a.x, a.b.x))
		{
			double k = (b.b.y - b.a.y) / (b.b.x - b.a.x),
						 b_ = b.a.y - b.a.x * k;
			return point(a.a.x, k * a.a.x + b_);
		}
		else
		{
			double k1 = (a.b.y - a.a.y) / (a.b.x - a.a.x),
						 k2 = (b.b.y - b.a.y) / (b.b.x - b.a.x),
						 b1 = a.a.y - a.a.x * k1,
						 b2 = b.a.y - b.a.x * k2,
						 x 	= (b2 - b1) / (k1 - k2),
						 y  = k1 * x + b1;
			return point(x, y);
		}
	}
};
typedef Geometry_Base::point gbp;
typedef Geometry_Base::segment gbs;

//===========================Geometry_Base=============