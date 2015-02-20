#include <stdio.h>
#define INF 1<<30
int a[50000];
int max(int a,int b)
{
	return a>b?a:b;
}
int maxSum(int i,int j)
{
	int t,sum=0,temp=0;
	for(t=i;t<=j;++t)
	{
		if(temp>0)
			temp+=a[t];
		else temp=a[t];
		if(temp>sum)
			sum=temp;
	}
	return sum;
}
int main()
{
	int c,n,i,ans;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d",&n);
		for(i=0;i<n;++i)
			scanf("%d",&a[i]);
		ans=-INF;
		for(i=0;i<n-1;++i)
			ans=max(ans,maxSum(0,i)+maxSum(i+1,n-1));
		printf("%d\n",ans);
	}
	return 0;
}