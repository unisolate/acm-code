#define maxn 1010

int ms() {
    int res = 0;
    char c;
    while (c = getchar(), c > '9' || c < '0')
        ;
    for (res = c - '0'; c = getchar(), c >= '0' && c <= '9';
         res = res * 10 + c - '0')
        ;
    return res;
}

void construct(bool g[maxn][maxn], int n, int* arr, int start) {
    static int nxt[maxn];
    memset(nxt, 255, sizeof(nxt));

    int head = start;
    for (int i = 0; i < n; i++) {
        if (i == start)
            continue;
        if (g[i][head]) {
            nxt[i] = head;
            head = i;
        } else {
            int prev = head;
            int iter = nxt[head];
            while (1) {
                if (iter == -1 || g[i][iter]) {
                    nxt[prev] = i;
                    nxt[i] = iter;
                    break;
                }
                prev = iter;
                iter = nxt[iter];
            }
        }
    }
    int i = 0;
    for (int x = head; x != -1; x = nxt[x]) {
        arr[i++] = x;
    }
}

bool g[maxn][maxn];
int n;
int arr[maxn];

/**
 * hdu-3414	竞赛图构造哈密顿圈
 */

int main() {
    while (scanf("%d", &n), n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = ms();
            }
        }
        if (n == 1) {  //只有一个点
            printf("1\n");
            continue;
        }
        for (int i = 0; i < n; i++) {  //枚举每一个起始点
            construct(g, n, arr, i);
            if (g[arr[n - 1]][arr[0]]) {
                for (int i = 0; i < n; i++) {
                    if (i != 0)
                        printf(" ");
                    printf("%d", arr[i] + 1);
                }
                printf("\n");
                goto out;
            }
        }
        printf("-1\n");  //没有哈密顿圈
                out:;
	}
	return 0;
}
