#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char str[500];
    int n,i,m;
    while (scanf("%s",str)==1)
    {
        for(n=0;n<strlen(str);n++)
        {
            if (isdigit(str[n]))
            {
                if (isdigit(str[n-1]))
                    i+=str[n]-48;else
                i=str[n]-48;
            }else
            if (isalpha(str[n]) && str[n] != 'b')
            {
                for(m=0;m<i;m++)
                    printf ("%c",str[n]);
            }else
            if (str[n]== '!')
                printf ("\n");else
            if (str[n]== '*')
            {
                for(m=0;m<i;m++)
                    printf ("*");
            }else
            if (str[n]== 'b')
            {
                for(m=0;m<i;m++)
                    printf (" ");
            }
        }
    printf ("\n");
    }
    return 0;
}
 //remained to be optimized!!
 /*
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
*/
