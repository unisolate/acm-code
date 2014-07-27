#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *a=NULL,i,n,max1=0,max2=0,max3=0;
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf(" %d",a+i);
    }
    for(i=0;i<n;i++)
        if(max1<a[i])
            max1=a[i];
    for(i=0;i<n;i++)
        if(max2<a[i] && a[i]<max1)
            max2=a[i];
    for(i=0;i<n;i++)
        if(max3<a[i] && a[i]<max2)
            max3=a[i];
    printf("%d %d %d",max1,max2,max3);
    return 0;
}
