#include<stdio.h>
#include<math.h>
int main()
{
	const double epsilon=1.0e-5;
	int i;
	double m,length;
	while(scanf("%lf",&length) && fabs(length-0.0)>epsilon)
	{
		for(i=2,m=0;length-m>epsilon;i++)
			m+=(double)1/i;
		printf("%d card(s)\n",i-2);
	}
	return 0;
}