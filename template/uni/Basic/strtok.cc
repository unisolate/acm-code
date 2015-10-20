// 读取不定量空格分隔的整数
gets(buf);
int v;
char *p = strtok(buf," ");
while(p) {
    sscanf(p,"%d",&v);
    p = strtok(NULL," ");
}