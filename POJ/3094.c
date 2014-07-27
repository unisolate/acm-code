#include<stdio.h>
#include<string.h>
int main()
{
	int i,sum;
	char line[300];
	gets(line);
	while(line[0]!='#')
	{
		for(i=0,sum=0;i<strlen(line);i++)
			if(line[i]!=' ')
				sum+=(i+1)*(line[i]-'A'+1);
		printf("%d\n",sum);
		gets(line);
	}
	return 0;
}