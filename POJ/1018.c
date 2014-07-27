#include <stdio.h>
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int m,n,j,k,band,price,fminband=0,sumprice=0;
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			int maxband,minprice;
			double bp=0;
			scanf("%d",&m);
			for(k=0;k<m;k++)
			{
				scanf("%d %d",&band,&price);
				if(bp<(double)band/price)
				{
					bp=(double)band/price;
					maxband=band;
					minprice=price;
				}
			}
			sumprice+=minprice;
			fminband=maxband;
		}
		printf("%.3f",(double)fminband/sumprice);
	}
	return 0;
}