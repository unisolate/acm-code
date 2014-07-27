#include<stdio.h>
int main()
{
	int i,j,num;
	for(i=1;i<10;i++)
	{
		for(j=1;j<=i;j++)
		{
			num=i*j;
			printf("%d*%d=%-3d",j,i,num);
		}
		printf("\n");
	}
	return 0;
}