#include<stdio.h>

int a1, b1, c1, a2, b2, c2, t, i;

void work ();
void print ();

int main ()
{

	scanf("%d", &t);
	for (i = 1; i <= t; i++)
	{
		scanf("%d%d%d%d%d%d", &a1, &b1, &c1, &a2, &b2, &c2);
		work();
	}

	return 0;
}

void work ()
{
	if ((a1*b2 == b1*a2)&&(b1*c2 == c1*b2))
	{
		printf("Infinite\n");
		return;
	}
	if ((a1*b2 == b1*a2)&&(b1*c2 != c1*b2))
	{
		printf("No solution\n");
		return;
	}

	int det = a1*b2 - a2*b1;
	int x, y, tx, ty;

	x = b2*c1-b1*c2;
	y = -(a2*c1-a1*c2);
	tx = x*1000/det;
	ty = y*1000/det;

	print(tx);
	printf(" ");
	print(ty);
	printf("\n");
}

void print (int n)
{
	int a[4], fu = 0;

	if (n == 0) { printf("0.00"); return; }
	if (n < 0) { fu = 1; n = -n; }

	if (n%10 > 4)
	{
		a[2] = n%100/10+1;
		a[1] = n%1000/100;
		a[0] = n/1000;
		a[1] += a[2]/10;
		a[0] += a[1]/10;
		a[2] %= 10;
		a[1] %= 10;
	}
	else
	{
		a[2] = n%100/10;
		a[1] = n%1000/100;
		a[0] = n/1000;
	}
	if (fu) printf("%d", -a[0]); else printf("%d", a[0]);
	printf(".%d%d", a[1], a[2]);
}


/*#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,t;
    double x[1000],y[1000];
    //scanf("%d",&t);
    x[0]=0.005;
    y[0]=9.995;
    for(i=1;i<1000;i++)
    {
        x[i]=x[i-1]+0.01;
        y[i]=y[i-1]-0.01;
    }
    for(i=0;i<200;i++)
    {
        //printf("%.3f %.3f\n",x[i],y[i]);
        printf("%.2lf %.2lf\n",x[i],y[i]);
    }
    return 0;
}
/*int main()
{

    double a1,a2,b1,b2,c1,c2;
    double x,y;
    int flag=0;//0表示有唯一解，1表示无解，2表示无穷多解
    scanf("%lf %lf %lf",&a1,&b1,&c1);
    scanf("%lf %lf %lf",&a2,&b2,&c2);

    if(a1!=0)
    {
             if(b2-a2*b1/a1!=0)
             {
                 y=(a2*c1/a1-c2)/(b2-a2*b1/a1);
                 x=-(b1*y+c1)/a1;
             }else
             {
                 if(a2*c1/a1-c2!=0)flag=1;//无解
                 else flag=2;//无穷解
             }
    }else
    {
             if(b1!=0)
             {
                 if(a2!=0)
                 {
                      x=(c1*b2/b1-c2)/a2;
                      y=-c1/b1;
                 }else
                 {
                      if(c1*b2/b1-c2!=0)flag=1;//无解
                      else flag=2;//无穷解
                 }
             }else
             {
                  if(c1!=0)flag=1;//无解
                  else flag=2;//无穷解
             }
    }

    if(flag==0)
    {
              printf("%.2lf2 %.2lf\n",x,y);
    }else
    {
         if(flag==1)printf("No solution\n");
         else printf("Infinite solutions\n");
    }
    system("pause");
}*/
