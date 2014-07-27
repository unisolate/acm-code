#include<stdio.h>
#include<ctype.h>
int main()
{
	char[100] num;
	while(gets(num)!=EOF)
	{
		if(isdigit(num))
			printf("%d\n",num-'0'+1);else
		if(isupper(num))
			printf("%d\n",num-'A'+11);else
		if(islower(num))
			printf("%d\n",num-'a'+37);else
		printf("such number is impossible!\n");
	}
	return 0;
}