#include<stdio.h>
int main()
{
    char num[13];
    scanf("%s",num);
    int i,n[10],sum=0;
    n[0]=num[0]-48;
    n[1]=num[2]-48;
    n[2]=num[3]-48;
    n[3]=num[4]-48;
    n[4]=num[6]-48;
    n[5]=num[7]-48;
    n[6]=num[8]-48;
    n[7]=num[9]-48;
    n[8]=num[10]-48;
    if(num[12]!='X')
        n[9]=num[12]-48;else
        n[9]=10;
    for(i=1;i<=9;i++)
        sum+=i*n[i-1];
    if(sum%11==n[9])
        printf("Right");else
        {
            if(sum%11<10)
                num[12]=sum%11+48;else
                num[12]='X';
            printf("%s",num);
        }
    return 0;
}
