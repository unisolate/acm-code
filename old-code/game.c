#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //存储按键码
char key;//x、y、i用于循环，x0y0指示当前空位"0"，rnd存放随机数值，t标记排序是否成功
int x,y,x0,y0,rnd,i,t=0;//数字存储矩阵
int matrix[4][4]; //以下为函数声明void show(void); //显示当前排序
void initmatrix(void); //初始化随机矩阵
int sett(void); //判断当前排序是否成功
void up(void); //向下移动空位（空位下方数字上移）
void down(void);
void lft(void);
void rght(void);
void iptkey(void); //接收按键（只接收方向键）//主函数
int main(void)
{//显示提示信息并暂停 按任意键后开始游戏
printf("Use arrow key to move the numbers,press anykey to start playing.\n");
getch();//标号 游戏成功后如果按r重玩则跳转至此
start://清成功标志，否则一直为成功状态
t=0; //取随机数初始化
srand((unsigned int)time(0));
initmatrix();//排序不成功一直获取方向键并操作矩阵数字交换
while(!t)
{
iptkey();
t=sett();//清屏
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
for(y=0;y<4;y++) //嵌套循环先按成功序列排序1234567891011121314150
for(x=0;x<4;x++)
{
if(y==3 && x==3)
matrix[y][x]=0;
else
matrix[y][x]=1+i++;
}
for(i=0;i<1000;i++) //一千次循环，每次循环都按随即方向移动
{
rnd=rand()%(4); //取0-3随机数，分别代表上下左右四个方向
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
if(y0!=3) //移动时要考虑空位"0"是否已经在边界，上下左右各边界各有一个方向不能移动
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
printf("%d\n",matrix[y][x]); //|“\n"保证每行只有四个数显示 满四个数就换行
else
printf("%d\t",matrix[y][x]);
}
}
