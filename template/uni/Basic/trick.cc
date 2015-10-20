// C++ 扩栈
#pragma comment(linker, "/STACK:1024000000,1024000000")

// 读取空格分隔的数据（个数不定）
gets(buf);
int v;
char *p = strtok(buf, " ");
while (p) {
    sscanf(p, "%d", &v);  // v = atoi(p);
    p = strtok(NULL, " ");
}

// 读取空格分隔的字符串（个数确定）
while (gets(s), s[0]) {
    sscanf(s, "%s%s", a, b);
    m[string(b)] = string(a);
}

// string 与 char* 互转
char a[42];
string b = string(a);
printf("%s", b.c_str());

// string 中寻找字符
string s;
if (s.find('+') != string::npos) {
    // s.find('+') 类型为 size_type
}

// string 中消除指定字符
string t = "";
for (int j = 0; j < (int)s.size(); ++j) {
    if (s[j] != '.') {
        t += s[j];
    }
}
s = t;

// 优先队列结构体比较（从小到大）
struct P {
    int a, b;
    bool operator<(const P &x) const {
        return b > x.b;
    }
}