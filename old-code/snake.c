#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#define LENX 30
#define LENY 20 // 场地大小
#define MAX_LEN (LENX * LENY) // 蛇最长可能
typedef struct snakeElem {// 蛇一节的结构，其实只包括坐标信息x，y
 int x;
 int y;
}snakeElem;
int g_map[LENY][LENX]; // 地图一张，大小30x20，随意修改0处的值
// 可以得到不同的地图，随机修改g_map[randY][randX]的值为1生成随机地图
int g_foodX, g_foodY; // 食物的坐标点，会随机生成
int g_snakeLen; // 蛇当前长度，初始值为5
int g_score; // 当前分数，初始化为0分
int g_speed; // 速度，值越大越慢，实际是Sleep的间隔秒数
char g_direction; // 一开始，蛇向右移动
char g_tmpD; // 对按键进行预判
snakeElem g_snake[MAX_LEN]; // 初始小蛇位置以及形状，这货就是一长条形
// 一些用得到的函数
void initMap() {// 初始化地图
 int i, j;
 for (i = 0; i < LENY; ++i)
  for (j = 0; j < LENX; ++j)
   if ((i == 0 || i == LENY - 1) || (j == 0 || j == LENX - 1))
    g_map[i][j] = 1;
   else
    g_map[i][j] = 0;
}
void gotoxy(int xpos, int ypos) {// 作用是将光标移动到屏幕参数指定坐标
 COORD scrn;
 HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
 scrn.X = xpos; scrn.Y = ypos;
 SetConsoleCursorPosition(hOuput,scrn);
}
//int isOnTheSnake(int x, int y, int flag = 1) { // C语言不让用默认参数我擦！
int isOnTheSnake(int x, int y, int flag) {
 // 判断当前坐标是否在蛇身上，flag标记是否判断蛇头
 int i;
 if (flag) {
  for (i = 0; i < g_snakeLen; ++i)
   if (x == g_snake[i].x && y == g_snake[i].y)
    return 1;
 }
 else
  for (i = 0; i < g_snakeLen - 1; ++i)
   if (x == g_snake[i].x && y == g_snake[i].y)
    return 1;
 return 0;
}
void drawObstacle() {// 生成障碍物
 int i, j;
 int k;
 srand(time(NULL)); // 初始化时间种子
 k = rand() % 11; // 随机产生不超过10个障碍块
 while (k--) {
  i = rand() % 19 + 1;
  j = rand() % 29 + 1;
  if (isOnTheSnake(j, i, 1))
   continue;
  g_map[i][j] = 1;
 }
}
void drawBorder(char fill) {// 根据传参，画贪吃蛇的地图
 int i, j;
 for (i = 0; i < LENY; ++i)
  for (j = 0; j < LENX; ++j)
   if (g_map[i][j]) {
    gotoxy(j, i);
    putchar(fill);
   }
 gotoxy(LENX + 1, LENY - 1);
 puts("Score: ");
}
void initSnake() {// 根据小蛇结构，画出最开始的小蛇
 int i = 0;
 for (; i < g_snakeLen; ++i) {
  g_snake[i].x = i + 1;
  g_snake[i].y = 5;
  gotoxy(g_snake[i].x, g_snake[i].y);
  putchar('@');
 }
}
void createFood() {// 随机生成食物
 srand(time(NULL)); // 初始化时间种子
 do {//不能把食物放在墙上，否则是在谋杀蛇，同理不能把食物丢蛇身上
  g_foodX = rand() % 29 + 1;
  g_foodY = rand() % 19 + 1;
 } while (g_map[g_foodY][g_foodX] || isOnTheSnake(g_foodX, g_foodY, 1));
 gotoxy(g_foodX, g_foodY);
 putchar('*');
}
void writeScore() {// 写分数
 gotoxy(LENX + 8, LENY - 1);
 printf("%d", g_score);
}
void reset() {// 初始化游戏
 system("cls");
 g_snakeLen = 5; // 蛇当前长度，初始值为5
 g_score = 0; // 当前分数，初始化为0分
 g_speed = 250; // 速度，值越大越慢，实际是Sleep的间隔秒数
 g_direction = 77; // 一开始，蛇向右移动
 g_tmpD = '\0'; // 对按键进行预判
 initMap();
 drawObstacle();
 drawBorder('#');
 initSnake();
 createFood();
 writeScore();
}
void judgeOver() {// 判断移动后的小蛇情况，是挂掉还是长大，判断只需要考虑蛇头
 char again;
 if (g_map[g_snake[g_snakeLen - 1].y][g_snake[g_snakeLen - 1].x] ||
 isOnTheSnake(g_snake[g_snakeLen - 1].x, g_snake[g_snakeLen - 1].y, 0)) {
  // 撞墙或咬自己不解释，直接挂吧
  system("cls");
  puts("Game over!");
  Sleep(500);
  puts("Again?(Y/N)");
  again = getch();
  if (again == 'y' || again == 'Y') reset();
  else exit(0); // 正常退出，返回值0
 }
 else if(g_snake[g_snakeLen - 1].x == g_foodX &&
  g_snake[g_snakeLen - 1].y == g_foodY) {// 吃到食物了，成长并加速
  g_snake[g_snakeLen].x = g_foodX;
  g_snake[g_snakeLen].y = g_foodY;
  ++g_snakeLen; // 蛇长度增加
  g_speed -= 20; // 加快
  g_score += 10; // 分数增加
  createFood(); // 新生成食物
  writeScore(); // 刷新分数
 }
}
void run() {// 游戏主循环
 int i; // 用于循环的变量，不管它
 while (1) {
  if (kbhit())
   if ((char)getch() == -32)
    g_tmpD = getch();
  if (g_tmpD == 75 || g_tmpD == 77 || g_tmpD == 80 || g_tmpD == 72)
   if (g_tmpD + g_direction != 152) // 不能逆行
    g_direction = g_tmpD;
  gotoxy(g_snake[0].x, g_snake[0].y);
  putchar(' ');
  for (i = 0; i < g_snakeLen - 1; ++i) {
   g_snake[i].x = g_snake[i + 1].x;
   g_snake[i].y = g_snake[i + 1].y;
  }
  switch (g_direction) {
  case 75: --g_snake[g_snakeLen - 1].x; break; // 向左
  case 77: ++g_snake[g_snakeLen - 1].x; break; // 向右
  case 80: ++g_snake[g_snakeLen - 1].y; break; // 向下
  case 72: --g_snake[g_snakeLen - 1].y; break; // 向上
  }
  judgeOver();
  gotoxy(g_snake[g_snakeLen - 1].x, g_snake[g_snakeLen - 1].y);
  putchar('@');
  Sleep(g_speed);
 }
}
int main() {// 主函数，3行
 reset();
 run();
 return 0;
}
