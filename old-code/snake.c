#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#define LENX 30
#define LENY 20 // ���ش�С
#define MAX_LEN (LENX * LENY) // �������
typedef struct snakeElem {// ��һ�ڵĽṹ����ʵֻ����������Ϣx��y
 int x;
 int y;
}snakeElem;
int g_map[LENY][LENX]; // ��ͼһ�ţ���С30x20�������޸�0����ֵ
// ���Եõ���ͬ�ĵ�ͼ������޸�g_map[randY][randX]��ֵΪ1���������ͼ
int g_foodX, g_foodY; // ʳ�������㣬���������
int g_snakeLen; // �ߵ�ǰ���ȣ���ʼֵΪ5
int g_score; // ��ǰ��������ʼ��Ϊ0��
int g_speed; // �ٶȣ�ֵԽ��Խ����ʵ����Sleep�ļ������
char g_direction; // һ��ʼ���������ƶ�
char g_tmpD; // �԰�������Ԥ��
snakeElem g_snake[MAX_LEN]; // ��ʼС��λ���Լ���״���������һ������
// һЩ�õõ��ĺ���
void initMap() {// ��ʼ����ͼ
 int i, j;
 for (i = 0; i < LENY; ++i)
  for (j = 0; j < LENX; ++j)
   if ((i == 0 || i == LENY - 1) || (j == 0 || j == LENX - 1))
    g_map[i][j] = 1;
   else
    g_map[i][j] = 0;
}
void gotoxy(int xpos, int ypos) {// �����ǽ�����ƶ�����Ļ����ָ������
 COORD scrn;
 HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
 scrn.X = xpos; scrn.Y = ypos;
 SetConsoleCursorPosition(hOuput,scrn);
}
//int isOnTheSnake(int x, int y, int flag = 1) { // C���Բ�����Ĭ�ϲ����Ҳ���
int isOnTheSnake(int x, int y, int flag) {
 // �жϵ�ǰ�����Ƿ��������ϣ�flag����Ƿ��ж���ͷ
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
void drawObstacle() {// �����ϰ���
 int i, j;
 int k;
 srand(time(NULL)); // ��ʼ��ʱ������
 k = rand() % 11; // �������������10���ϰ���
 while (k--) {
  i = rand() % 19 + 1;
  j = rand() % 29 + 1;
  if (isOnTheSnake(j, i, 1))
   continue;
  g_map[i][j] = 1;
 }
}
void drawBorder(char fill) {// ���ݴ��Σ���̰���ߵĵ�ͼ
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
void initSnake() {// ����С�߽ṹ�������ʼ��С��
 int i = 0;
 for (; i < g_snakeLen; ++i) {
  g_snake[i].x = i + 1;
  g_snake[i].y = 5;
  gotoxy(g_snake[i].x, g_snake[i].y);
  putchar('@');
 }
}
void createFood() {// �������ʳ��
 srand(time(NULL)); // ��ʼ��ʱ������
 do {//���ܰ�ʳ�����ǽ�ϣ���������ıɱ�ߣ�ͬ���ܰ�ʳ�ﶪ������
  g_foodX = rand() % 29 + 1;
  g_foodY = rand() % 19 + 1;
 } while (g_map[g_foodY][g_foodX] || isOnTheSnake(g_foodX, g_foodY, 1));
 gotoxy(g_foodX, g_foodY);
 putchar('*');
}
void writeScore() {// д����
 gotoxy(LENX + 8, LENY - 1);
 printf("%d", g_score);
}
void reset() {// ��ʼ����Ϸ
 system("cls");
 g_snakeLen = 5; // �ߵ�ǰ���ȣ���ʼֵΪ5
 g_score = 0; // ��ǰ��������ʼ��Ϊ0��
 g_speed = 250; // �ٶȣ�ֵԽ��Խ����ʵ����Sleep�ļ������
 g_direction = 77; // һ��ʼ���������ƶ�
 g_tmpD = '\0'; // �԰�������Ԥ��
 initMap();
 drawObstacle();
 drawBorder('#');
 initSnake();
 createFood();
 writeScore();
}
void judgeOver() {// �ж��ƶ����С��������ǹҵ����ǳ����ж�ֻ��Ҫ������ͷ
 char again;
 if (g_map[g_snake[g_snakeLen - 1].y][g_snake[g_snakeLen - 1].x] ||
 isOnTheSnake(g_snake[g_snakeLen - 1].x, g_snake[g_snakeLen - 1].y, 0)) {
  // ײǽ��ҧ�Լ������ͣ�ֱ�ӹҰ�
  system("cls");
  puts("Game over!");
  Sleep(500);
  puts("Again?(Y/N)");
  again = getch();
  if (again == 'y' || again == 'Y') reset();
  else exit(0); // �����˳�������ֵ0
 }
 else if(g_snake[g_snakeLen - 1].x == g_foodX &&
  g_snake[g_snakeLen - 1].y == g_foodY) {// �Ե�ʳ���ˣ��ɳ�������
  g_snake[g_snakeLen].x = g_foodX;
  g_snake[g_snakeLen].y = g_foodY;
  ++g_snakeLen; // �߳�������
  g_speed -= 20; // �ӿ�
  g_score += 10; // ��������
  createFood(); // ������ʳ��
  writeScore(); // ˢ�·���
 }
}
void run() {// ��Ϸ��ѭ��
 int i; // ����ѭ���ı�����������
 while (1) {
  if (kbhit())
   if ((char)getch() == -32)
    g_tmpD = getch();
  if (g_tmpD == 75 || g_tmpD == 77 || g_tmpD == 80 || g_tmpD == 72)
   if (g_tmpD + g_direction != 152) // ��������
    g_direction = g_tmpD;
  gotoxy(g_snake[0].x, g_snake[0].y);
  putchar(' ');
  for (i = 0; i < g_snakeLen - 1; ++i) {
   g_snake[i].x = g_snake[i + 1].x;
   g_snake[i].y = g_snake[i + 1].y;
  }
  switch (g_direction) {
  case 75: --g_snake[g_snakeLen - 1].x; break; // ����
  case 77: ++g_snake[g_snakeLen - 1].x; break; // ����
  case 80: ++g_snake[g_snakeLen - 1].y; break; // ����
  case 72: --g_snake[g_snakeLen - 1].y; break; // ����
  }
  judgeOver();
  gotoxy(g_snake[g_snakeLen - 1].x, g_snake[g_snakeLen - 1].y);
  putchar('@');
  Sleep(g_speed);
 }
}
int main() {// ��������3��
 reset();
 run();
 return 0;
}
