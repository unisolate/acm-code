// TODO：排序？查找？
char s[25], a[15], b[15];
map<string, string> m;
int main()
{
    while (gets(s), s[0])
    {
        sscanf(s, "%s%s", a, b);
        m[string(b)] = string(a);
    }
    while (gets(s))
        puts(m.find(s) != m.end() ? m[s].c_str() : "eh");
    return 0;
}