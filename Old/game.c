#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //�洢������
char key;//x��y��i����ѭ����x0y0ָʾ��ǰ��λ"0"��rnd��������ֵ��t��������Ƿ�ɹ�
int x,y,x0,y0,rnd,i,t=0;//���ִ洢����
int matrix[4][4]; //����Ϊ��������void show(void); //��ʾ��ǰ����
void initmatrix(void); //��ʼ���������
int sett(void); //�жϵ�ǰ�����Ƿ�ɹ�
void up(void); //�����ƶ���λ����λ�·��������ƣ�
void down(void);
void lft(void);
void rght(void);
void iptkey(void); //���հ�����ֻ���շ������//������
int main(void)
{//��ʾ��ʾ��Ϣ����ͣ ���������ʼ��Ϸ
printf("Use arrow key to move the numbers,press anykey to start playing.\n");
getch();//��� ��Ϸ�ɹ��������r��������ת����
start://��ɹ���־������һֱΪ�ɹ�״̬
t=0; //ȡ�������ʼ��
srand((unsigned int)time(0));
initmatrix();//���򲻳ɹ�һֱ��ȡ������������������ֽ���
while(!t)
{
iptkey();
t=sett();//����
system("CLS");
show();
}
printf("Congratulations,you win!\n");
printf("Press R to Restart,anykey to Quit,thank you for playing the Game!\n");
key=getch();
system("CLS");
if(key=='R' || key=='r')
goto start;
else
;
getch();
return 0;
}
void initmatrix(void)
{
x0=3;
y0=3;
i=0;
for(y=0;y<4;y++) //Ƕ��ѭ���Ȱ��ɹ���������1234567891011121314150
for(x=0;x<4;x++)
{
if(y==3 && x==3)
matrix[y][x]=0;
else
matrix[y][x]=1+i++;
}
for(i=0;i<1000;i++) //һǧ��ѭ����ÿ��ѭ�������漴�����ƶ�
{
rnd=rand()%(4); //ȡ0-3��������ֱ�������������ĸ�����
switch(rnd)
{
case 0:
{
up();
break;
}
case 1:
{
down();
break;
}
case 2:
{
lft();
break;
}
case 3:
{
rght();
break;
}
}
}
show();
}int sett(void)
{
i=0;
for(y=0;y<4;y++)
for(x=0;x<4;x++)
{
if (matrix[y][x]!=1+i++)
return (i==16)?1:0;
}
}void iptkey(void)
{
key=getch();
switch(key)
{
case 72:
{
up();
break;
}
case 80:
{
down();
break;
}
case 75:
{
lft();
break;
}
case 77:
{
rght();
break;
}
}
}
void up(void)
{
if(y0!=3) //�ƶ�ʱҪ���ǿ�λ"0"�Ƿ��Ѿ��ڱ߽磬�������Ҹ��߽����һ���������ƶ�
{
matrix[y0][x0]=matrix[y0+1][x0];
y0++;
matrix[y0][x0]=0;
}
}
void down(void)
{
if(y0!=0)
{
matrix[y0][x0]=matrix[y0-1][x0];
y0--;
matrix[y0][x0]=0;
}
}
void lft(void)
{
if(x0!=3)
{
matrix[y0][x0]=matrix[y0][x0+1];
x0++;
matrix[y0][x0]=0;
}
}
void rght(void)
{
if(x0!=0)
{
matrix[y0][x0]=matrix[y0][x0-1];
x0--;
matrix[y0][x0]=0;
}
}void show(void)
{
for(y=0;y<4;y++)
for(x=0;x<4;x++)
{
if(x==3)
printf("%d\n",matrix[y][x]); //|��\n"��֤ÿ��ֻ���ĸ�����ʾ ���ĸ����ͻ���
else
printf("%d\t",matrix[y][x]);
}
}
