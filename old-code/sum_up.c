#include<stdio.h>
int main(void)
{
    long num,times;
    unsigned long long sum=0;
    printf ("Please enter a number and I'll sum up from 1 to it.(enter 0 to quit.)\n");
    scanf ("%ld",&times);
    while (times>0)
    {
        for (num=1;num<=times;num++)
        {
            sum=sum+num*num;
        }
        printf ("Sum up is %lld.\n",sum);
        sum = 0;
        printf ("Please enter a number and I'll sum up from 1 to it.(enter 0 to quit.)\n");
        scanf ("%ld",&times);
    }
    return 0;
}
