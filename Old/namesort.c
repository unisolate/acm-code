#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,m;
	char name[10][100],temp[100];
	for(i=0;i<10;i++)
	{
		scanf("%s",name[i]);
	}
	for(i=0;i<10;i++)
		for(j=i+1;j<10;j++)
		{
			if(name[i][0]>name[j][0])
			{
				strcpy(temp,name[i]);
				strcpy(name[i],name[j]);
				strcpy(name[j],temp);
			}
		}
	for(i=0;i<10;i++)
		printf("%s\n",name[i]);
	return 0;
}