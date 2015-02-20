#include <stdio.h>
#include <malloc.h>
#include <math.h>

/* 栈的顺序存储表示 */
 #define STACK_INIT_SIZE 10 /* 存储空间初始分配量 */
 #define STACKINCREMENT 2 /* 存储空间分配增量 */
 typedef struct SqStack
 {
   SElemType *base; /* 在栈构造之前和销毁之后，base的值为NULL */
   SElemType *top; /* 栈顶指针 */
   int stacksize; /* 当前已分配的存储空间，以元素为单位 */
 }SqStack; /* 顺序栈 */

 /* bo3-1.c 顺序栈（存储结构由c3-1.h定义）的基本操作（9个） */
 int InitStack(SqStack *S)
 { /* 构造一个空栈S */
   (*S).base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
   if(!(*S).base)
     exit(OVERFLOW); /* 存储分配失败 */
   (*S).top=(*S).base;
   (*S).stacksize=STACK_INIT_SIZE;
   return 1;
 }

 int DestroyStack(SqStack *S)
 { /* 销毁栈S，S不再存在 */
   free((*S).base);
   (*S).base=NULL;
   (*S).top=NULL;
   (*S).stacksize=0;
   return 1;
 }

 int ClearStack(SqStack *S)
 { /* 把S置为空栈 */
   (*S).top=(*S).base;
   return 1;
 }

 int StackEmpty(SqStack S)
 { /* 若栈S为空栈，则返回1，否则返回0 */
   if(S.top==S.base)
     return 1;
   else
     return 0;
 }

 int StackLength(SqStack S)
 { /* 返回S的元素个数，即栈的长度 */
   return S.top-S.base;
 }

 int GetTop(SqStack S,SElemType *e)
 { /* 若栈不空，则用e返回S的栈顶元素，并返回1；否则返回0 */
   if(S.top>S.base)
   {
     *e=*(S.top-1);
     return 1;
   }
   else
     return 0;
 }

 int Push(SqStack *S,SElemType e)
 { /* 插入元素e为新的栈顶元素 */
   if((*S).top-(*S).base>=(*S).stacksize) /* 栈满，追加存储空间 */
   {
     (*S).base=(SElemType *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(SElemType));
     if(!(*S).base)
       exit(OVERFLOW); /* 存储分配失败 */
     (*S).top=(*S).base+(*S).stacksize;
     (*S).stacksize+=STACKINCREMENT;
   }
   *((*S).top)++=e;
   return 1;
 }

 int Pop(SqStack *S,SElemType *e)
 { /* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回1；否则返回0 */
   if((*S).top==(*S).base)
     return 0;
   *e=*--(*S).top;
   return 1;
 }

 int StackTraverse(SqStack S,int(*visit)(SElemType))
 { /* 从栈底到栈顶依次对栈中每个元素调用函数visit()。 */
   /* 一旦visit()失败，则操作失败 */
   while(S.top>S.base)
     visit(*S.base++);
   printf("\n");
   return 1;
 }
 