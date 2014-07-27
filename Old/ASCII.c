#include <stdio.h>//overflow
int main (void)
{
    int code;
    printf ("Please enter an ASCII code! (Enter q to quit.)\n");
    scanf ("%d",&code);
    printf ("Great! The code represents the letter \"%c\".",code);
    return 0;
}
//扩展：程序循环运行，按q退出，打印其他字符，错误提示
