#include<stdio.h>
#include<string.h>
int main()
{
	int n,m,i,j,k;
	scanf("%d %d",&n,&m);
	int sort[m];
	char dna[m][n];
	memset(sort,0,sizeof(sort));
	for(i=0;i<m;i++)
	{
		scanf("%s",dna[i]);
		for(j=0;j<n;j++)
		{
			for(k=j+1;k<n;k++)
			{
				if(dna[i][j]>dna[i][k])
					sort[i]++;
			}
		}
	}
	for(i=0;i<m;i++)
	{
		int min=0,minsort=10000;
		for(j=0;j<m;j++)
		{
			if(sort[j]<minsort)
			{
				minsort=sort[j];
				min=j;
			}
		}
		sort[min]=10000;
		for(k=0;k<n;k++)
			printf("%c",dna[min][k]);
		printf("\n");
	}
	return 0;
}