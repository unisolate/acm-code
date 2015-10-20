// 枚举长为 n 含 k 个 1 的 01 串
int n = 5, k = 3;
for (int s = (1 << k) - 1, u = 1 << n; s < u;)
{
	for (int i = 0; i < n; i++)
		printf("%d", (((s >> (n - 1 - i)) & 1) == 1));
	printf("\n");
	int b = s & -s;
	s = (s + b) | (((s ^ (s + b)) >> 2) / b);
}