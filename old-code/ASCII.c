#include <stdio.h>//overflow
int main (void)
{
    int code;
    printf ("Please enter an ASCII code! (Enter q to quit.)\n");
    scanf ("%d",&code);
    printf ("Great! The code represents the letter \"%c\".",code);
    return 0;
}
//��չ������ѭ�����У���q�˳�����ӡ�����ַ���������ʾ
