#include <stdio.h>
#include <string.h>

long tree[100001],s[20001],l[20001],r[20001];

void update(long i)
{
	for(;i<=100000;i+=(i&-i))
		tree[i]+=1;
}

long read(long i)
{
	long sum=0;
	for(;i>0;i-=(i&-i))
		sum+=tree[i];
	return sum;
}

int main()
{
	int t,i,n,j;
	long long ans;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		ans=0;
		memset(tree,0,sizeof(tree));
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			scanf("%ld",&s[j]);
			update(s[j]);
			l[j]=read(s[j]-1);
		}
		memset(tree,0,sizeof(tree));
		for(j=n;j>0;j--)
		{
			update(s[j]);
			r[j]=read(s[j]-1);
		}
		for(j=2;j<n;j++)
		{
			ans+=l[j]*(n-j-r[j])+r[j]*(j-1-l[j]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}