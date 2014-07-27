#include <stdio.h>
#define PI 3.1416
int main()
{
	double r,s,c;
	scanf("%lf",&r);
	s=PI*r*r;
	c=2*PI*r;
	printf("%.2lf %.2lf\n",c,s);
	return 0;
}