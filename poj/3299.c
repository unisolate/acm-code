#include<stdio.h>
#include<math.h>
int main()
{
	const double e=2.718281828 , epsilon=1.0e-5;
	double num1,num2,t,d,h;
	char m,n;
	while(scanf("%c",&m) && m!='E')
	{
		scanf("%lf %c%lf",&num1,&n,&num2);
		t=0;d=0;h=0;
		switch(m)
		{
			case 'T':
				t=num1;
				break;
			case 'D':
				d=num1;
				break;
			case 'H':
				h=num1;
				break;
		}
		switch(n)
		{
			case 'T':
				t=num2;
				break;
			case 'D':
				d=num2;
				break;
			case 'H':
				h=num2;
				break;
		}
		if(fabs(h-0.0) <= epsilon)
		{
			h = t + 0.5555 * ( 6.11 * pow(e , 5417.53 * ( 1/273.16 - 1/(d+273.16) ) ) - 10);
		}
		if(fabs(t-0.0) <= epsilon)
		{
			t = h - 0.5555 * ( 6.11 * pow(e , 5417.53 * ( 1/273.16 - 1/(d+273.16) ) ) - 10);
		}
		if(fabs(d-0.0) <= epsilon)
		{
			d = 1/( 1/273.16 - log( ( (h-t)/0.5555 + 10 )/6.11 )/5417.753 ) - 273.16;
		}
		printf("T %.1lf D %.1lf H %.1lf\n",t,d,h);
		getchar();
	}
	return 0;
}