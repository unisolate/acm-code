#include <stdio.h>

void max_heapify(int[] a,int i)
{
	int l=left(i);
	int r=right(i);
	if(l<=a.heapsize && a[l]>a[i])
		largest=l;else
		largest=i;
	if(r<=a.heapsize && a[r]>a[largest])
		largest=r;
	if(largest!=i)
	{
		swap(a[i],a[largest]);
		max_heapify(a,largest);
	}
}