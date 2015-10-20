const int MX = 1000;

char a[MX], b[MX];
int dp[MX][MX], path[MX][MX];

int Lcs(char x[], char y[]) {
    int i, j, len1 = strlen(x + 1), len2 = strlen(y + 1);
    memset(dp, 0, sizeof(dp));
    for (i = 1; i <= len1; ++i)
        for (j = 1; j <= len2; ++j) {
            if (x[i] == y[j])
                dp[i][j] = dp[i - 1][j - 1] + 1, path[i][j] = 1;
            else if (dp[i - 1][j] >= dp[i][j - 1])
                dp[i][j] = dp[i - 1][j], path[i][j] = 2;
            else
                dp[i][j] = dp[i][j - 1], path[i][j] = 3;
        }
    return dp[len1][len2];
}

void PrintLcs(int i, int j) {
    if (i == 0 || j == 0) return;
    if (path[i][j] == 1) {
        PrintLcs(i - 1, j - 1);
        putchar(a[i]);
    } else if (path[i][j] == 2) PrintLcs(i - 1, j);
    else PrintLcs(i, j - 1);
}

int main() {
    while (gets(a + 1)) {
        gets(b + 1);
        printf("%d\n", Lcs(a, b));
        PrintLcs(strlen(a + 1), strlen(b + 1));
        putchar(10);
    }
    return 0;
}
