#include<stdio.h>
#include<string.h>
int num[50000][2];
int main()
{
    int t,i,m,j,temp1,temp2;
    long n,k;
    memset(num,0,sizeof(num));

    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%ld %ld",&n,&k);
        for(m=0;m<n;m++)
            scanf("%d %d",&num[m][0],&num[m][1]);
        quicksort(0,n,num);
        /*for(m=0,temp1=0,temp2=0;m<n;m++)
        {
            for(j=m+1;j<n;j++)
            {
                if(num[m][0]==num[j][0] && num[m][1]<num[j][1])
                {
                    temp1=num[m][1];num[m][1]=num[j][1];num[j][1]=temp1;
                    j--;
                }
            }
        }*/
        /*for(m=0,temp1=0,temp2=0;m<n;m++)
        {
            for(j=m+1;j<n;j++)
            {
                if(num[m][0]<num[j][0])
                {
                    temp1=num[m][0];num[m][0]=num[j][0];num[j][0]=temp1;
                    temp2=num[m][1];num[m][1]=num[j][1];num[j][1]=temp2;
                }
                if(num[m][0]==num[j][0] && num[m][1]<num[j][1])
                {
                    temp1=num[m][1];num[m][1]=num[j][1];num[j][1]=temp1;
                    j--;
                }
            }
        }*/
        for(m=0;m<n;m++)
            printf("%d %d\n",num[m][0],num[m][1]);
        //printf("%d %d\n",num[k-1][0],num[k-1][1]);
    }
    return 0;
}

void quicksort(int l,int r,int b[])
{
    int i,j,x;
    if(l>=r) return;
    i=l;
    j=r;
    x=b;
    while(i!=j)
    {
        while(b[j]>x&&j>i) j--;
        if(i<j)
        {
            b=b[j][0];
            i++;
        }
        while(b<x&&j>i)i++;
        if(i<j)
        {
            b[j][0]=b;
            j--;
        }
    }
    b=x;
    quicksort(l,j-1,b);
    quicksort(i+1,r,b);
}
