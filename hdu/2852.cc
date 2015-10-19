#include <cstdio>
#include <cstring>
#define MX 100010
using namespace std;
int c[MX];
void U(int x, int v) {
	for (; x < MX; x += (x & -x)) {
		c[x] += v;
	}
}
int Q(int x) {
	if (x == 0) {
		return 0;
	}
	int r = 0;
	for (; x > 0; x -= (x & -x)) {
		r += c[x];
	}
	return r;
}
int lb(int l, int r, int v, int k) {
	int cnt = r - l, it, step;
	while (cnt > 0) {
		step = cnt / 2;
		it = l + step;
		if (Q(it) - v < k) {
			l = ++it;
			cnt -= step + 1;
		} else {
			cnt = step;
		}
	}
	return l;
}
int main() {
	int m, p, e, k;
	while (~scanf("%d", &m)) {
		memset(c, 0, sizeof(c));
		while (m--) {
			scanf("%d%d", &p, &e);
			if (p == 0) {
				U(e, 1);
			} else if (p == 1) {
				if (Q(e) - Q(e - 1)) {
					U(e, -1);
				} else {
					puts("No Elment!");
				}
			} else {
				scanf("%d", &k);
				int v = Q(e);
				if (lb(e + 1, MX, v, k) == MX) {
					puts("Not Find!");
				} else {
					printf("%d\n", lb(e + 1, MX, v, k));
				}
			}
		}
	}
	return 0;
}