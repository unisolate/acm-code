#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#define MX 105
using namespace std;
int a[MX], b[MX], c, n;
bool ok(int m) {
	int cnt = 0;
	int jud = c + m;
	for (int i = 2; i <= n; i++) {
		if (b[i] >= jud) {
			cnt += b[i] - jud + 1;
		}
	}
	return cnt <= m;
}
void solve(int l, int r) {
	int m;
	while (l + 1 < r) {
		m = (l + r) / 2;
		ok(m) ? r = m : l = m;
	}
	printf("%d\n", r);
}
int main() {
	int x = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
		x += a[i];
	}
	c = a[1];
	sort(a + 1, a + n + 1);
	if (c == a[n]) {
		if (a[n] == a[n - 1])
			puts("1");
		else
			puts("0");
	}
	else solve(0, x + 1);
	return 0;
}