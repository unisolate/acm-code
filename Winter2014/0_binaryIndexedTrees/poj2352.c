#include <stdio.h>
#include <string.h>

int level[15050];
int tree[32101];

void update(int i)
{
	for(;i<=32100;i+=(i&-i))
		tree[i]+=1;
}

int sum(int i)
{
	int sum=0;
	for(;i>0;i-=(i&-i))
		sum+=tree[i];
	return sum;
}

int main()
{
	memset(level,0,sizeof(level));
	memset(tree,0,sizeof(tree));
	int n,i,x,y;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		level[sum(x+1)]++;
		update(x+1);
	}
	for(i=0;i<n;i++)
		printf("%d\n",level[i]);
	return 0;
}