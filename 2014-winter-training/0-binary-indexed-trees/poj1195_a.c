#include <stdio.h>
#include <string.h>

int c[1025][1025];
int s;

void update(int x,int y,int val)
{
	int y1;
	while(x<=s+1)
	{
		y1=y;
		while(y1<=s+1)
		{
			c[x][y1]+=val;
			y1+=(y1&-y1);
		}
		x+=(x&-x);
	}
}

int read(int x,int y)
{
	int sum=0,y1;
	while(x>0)
	{
		y1=y;
		while(y1>0)
		{
			sum+=c[x][y1];
			y1-=(y1&-y1);
		}
		x-=(x&-x);
	}
	return sum;
}

int main()
{
	memset(c,0,sizeof(c));
	int flag, x,y,a, l,b,r,t;
	scanf("%d %d",&flag,&s);
	while(scanf("%d",&flag) && flag!=3)
	{
		if(flag==1)
		{
			scanf("%d %d %d",&x,&y,&a);
			update(x+1,y+1,a);
		}
		if(flag==2)
		{
			scanf("%d %d %d %d",&l,&b,&r,&t);
			printf("%d\n",read(r+1,t+1)+read(l,b)-read(l,t+1)-read(r+1,b));
		}
	}
	return 0;
}