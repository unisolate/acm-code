#define MAXW 100010
#define MAXL 12
const int MAXN = MAXW * MAXL;

struct node {
    int next[26];
    int cnt;  // 附加信息
} t[MAXN];

int ts;

void clear() {
    ts = 0;
    memset(t, 0, sizeof(t));
}

int insert(char s[]) {
    int len = strlen(s), p = 0;
    for (int i = 0; i < len; ++i) {
        if (!t[p].next[s[i] - 'a']) {
            t[p].next[s[i] - 'a'] = ++ts;
        }
        ++t[p].cnt;
        p = t[p].next[s[i] - 'a'];
    }
    return ++t[p].cnt;
}

int query(char s[]) {
    int len = strlen(s), p = 0;
    for (int i = 0; i < len; ++i) {
        if (!t[p].next[s[i] - 'a']) {
            return 0;
        }
        p = t[p].next[s[i] - 'a'];
    }
    return t[p].cnt;
}

int main() {
    char s[MAXL];
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        insert(s);
    }
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        printf("%d\n", query(s));
    }
    return 0;
}