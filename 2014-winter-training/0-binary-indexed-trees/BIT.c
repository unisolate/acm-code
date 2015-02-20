#include <stdio.h>

int lowbit(int x)
{
	return x&(-x);
}

int read(int idx)
{
	int sum=0;
	while(idx>0)
	{
		sum+=tree[idx];
		idx-=(idx&-idx);
	}
	return sum;
}

void update(int idx,int val)
{
	while(idx<=MaxVal)
	{
		tree[idx]+=val;
		idx+=(idx&-idx);
	}
}

int readSingle(int idx)
{
	int sum=tree[idx];
	if(idx>0)
	{
		int z=idx-(idx&-idx);
		idx--;
		while(idx!=z)
		{
			sum-=tree[idx];
			idx-=(idx&-idx);
		}
	}
	return sum;
}

void scale(int c)
{
	for(int i=1;i<MaxVal;i++)
		tree[i]=tree[i]/c;
}

void update2D(int x,int y,int val)
{
	int y1;
	while(x<=max_x)
	{
		y1=y;
		while(y1<=max_y)
		{
			tree[x][y1]+=val;
			y1+=(y1&-y1);
		}
		x+=(x&-x);
	}
}