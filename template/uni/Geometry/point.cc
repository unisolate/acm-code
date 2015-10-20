struct point {
    double x, y;
    point() {
    }
    point(double _x, double _y) : x(_x), y(_y){};
    void input() {
        scanf("%lf%lf", &x, &y);
    }
    void output() {
        printf("%.2f %.2f\n", x, y);
    }
    bool operator==(point a) const {
        return dblcmp(a.x - x) == 0 && dblcmp(a.y - y) == 0;
    }
    bool operator<(point a) const {
        return dblcmp(a.x - x) == 0 ? dblcmp(y - a.y) < 0 : x < a.x;
    }
    double len() {
        return hypot(x, y);
    }
    double len2() {
        return x * x + y * y;
    }
    double distance(point p) {
        return hypot(x - p.x, y - p.y);
    }
    point add(point p) {
        return point(x + p.x, y + p.y);
    }
    point sub(point p) {
        return point(x - p.x, y - p.y);
    }
    point mul(double b) {
        return point(x * b, y * b);
    }
    point div(double b) {
        return point(x / b, y / b);
    }
    double dot(point p)  //点积
    {
        return x * p.x + y * p.y;
    }
    double det(point p)  //叉积
    {
        return x * p.y - y * p.x;
    }
    double rad(point a, point b) {
        point p = *this;
        return fabs(
            atan2(fabs(a.sub(p).det(b.sub(p))), a.sub(p).dot(b.sub(p))));
    }
    point trunc(double r) {
        double l = len();
        if (!dblcmp(l))
            return *this;
        r /= l;
        return point(x * r, y * r);
    }
    point rotleft() {
        return point(-y, x);
    }
    point rotright() {
        return point(y, -x);
    }
    point rotate(point p, double angle)  //绕点p逆时针旋转angle角度
    {
        point v = this->sub(p);
        double c = cos(angle), s = sin(angle);
        return point(p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c);
    }
};