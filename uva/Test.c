#include<stdio.h>
#include<string.h>
int main()
{
    int sum,i,j,n;
    char str[10000];
    while(gets(str)!=NULL)
    {
        n=strlen(str);
        sum=0;
        for(i=0;i<n;i++)
        {
            if(str[i]>='0'&&str[i]<='9')
            {
                sum+=str[i]-'0';
            }
            else if(str[i]=='!')
            {
                printf("\n");
                sum=0;
            }
            else if(str[i]=='b')
            {
                for(j=0;j<sum;j++)
                printf(" ");
                sum=0;
            }
            else
            {
                for(j=0;j<sum;j++)
                printf("%c",str[i]);
                sum=0;
            }
        }
        printf("\n");
    }
    return 0;
}
