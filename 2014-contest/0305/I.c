#include <stdio.h>
struct star{
	long long x,y;
}s[2222];
int main()
{
	int t,i,n,j,k;
	scanf("%d",&t);
	while(t--)
	{
		int sum=0;
		scanf("%d",&n);
		for(i=0;i<n;++i)
			scanf("%I64d%I64d",&s[i].x,&s[i].y);
		for(i=0;i<n-2;++i)
			for(j=i+1;j<n-1;++j)
				for(k=j+1;k<n;++k)
				{
					long long a=(s[i].x-s[j].x)*(s[i].x-s[j].x)+(s[i].y-s[j].y)*(s[i].y-s[j].y);
					long long b=(s[i].x-s[k].x)*(s[i].x-s[k].x)+(s[i].y-s[k].y)*(s[i].y-s[k].y);
					long long c=(s[j].x-s[k].x)*(s[j].x-s[k].x)+(s[j].y-s[k].y)*(s[j].y-s[k].y);
					if(a+b>c&&a+c>b&&b+c>a)
						sum++;
				}
		printf("%d\n",sum);
	}
}