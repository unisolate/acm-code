#include <stdio.h>
typedef struct {int num,tim,sum;} sms;
sms heap[1000];
void add(sms t)
{
	heapsize++;
}
void out(int k)
{
	while(k>0)
	{
		printf("%d\n",heap[0].num);
		heap[0].sum+=heap[0].tim;
		modify(n);
		k--;
	}
}
void modify(int n)
{
	sms temp=heap[0];
	int i=0;
	int j=(i<<1)+1;
	while(j<=n-1)
	{
		if(j<n-1 && heap[j].sum>heap[j+1].sum)
			j++;else
		if(j<n-1 && heap[j].sum==heap[j+1].sum && heap[j].num>heap[j+1.num])
			j++;
		if(heap[j].sum<temp.sum)
		{
			heap[i]=heap[j];
			i=j;
		}else
		if(heap[j].sum>temp.sum)
			break;else
		if
	}
}
int main()
{
	int i=0,k;
	char line[10];
	while(scanf("%s",line) && line[0]!='#')
	{
		sms temp;
		scanf("%d %d",&temp.num,&temp.tim);
		temp.sum=temp.tim;
		add(temp);
		i++;
	}
	scanf("%d",&k);
	out(k);
	return 0;
}

