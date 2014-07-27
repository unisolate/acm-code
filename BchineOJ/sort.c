#include<stdio.h>
int main()
{
    int *a=NULL,i,n,max1=0,max2=0,max3=0;
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf(" %d",a+i);
    }
    quicksort(0,n-1,a);
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}

void shellsort(int a[],int n)
{
    int i,j,g;
    int temp,k;
    g=n/2;
    while(g!=0)
        {
        for(i=g+1;i<=n;i++)
            {
            temp=a[i];
            j=i-g;
            while(j>0)
                {
                k=j+g;
                if(a[j]<=a[k])
                    j=0;
                else
                    {
                    temp=a[j];a[j]=a[k];a[k]=temp;
                    }
                j=j-g;
                }
            }
        g=g/2;
        }
}

void quicksort(int l,int r,int b[])
{
    int i,j,x;
    if(l>=r) return;
    i=l;
    j=r;
    x=b[i];
    while(i!=j)
        {
        while(b[j]>x&&j>i) j--;
        if(i<j)
            {
            b[i]=b[j];
            i++;
            }
        while(b[i]<x&&j>i)i++;
            if(i<j)
                {
                b[j]=b[i];
                j--;
                }
        }
    b[i]=x;
    quicksort(l,j-1,b);
    quicksort(i+1,r,b);
}
