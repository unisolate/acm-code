#include<stdio.h>
int fib(int a)
{
	if(a>2)
	{
		a=fib(a-1)+fib(a-2);
		return a;
	}else
	return 1;
}
int main()
{
	int i;
	for(i=1;i<=10;i++)
		printf("%d\n",fib(i));
	return 0;
}