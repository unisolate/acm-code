#include<stdio.h>
#include<math.h>
int main()
{
	const double pai=3.1415926;
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int a=1,s=50;
		double x,y,r,l;
		scanf("%lf %lf",&x,&y);
		r=sqrt(x*x+y*y);
		l=sqrt(2*s/pai);
		while(r>l)
		{
			s+=50;
			l=sqrt(2*s/pai);
			a++;
		}
		printf("Property %d: This property will begin eroding in year %d.\n",i+1,a);
	}
	printf("END OF OUTPUT.");
	return 0;
}