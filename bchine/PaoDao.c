#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char a[100];
    gets(a);
    int n,num=0,alpha=0,space=0,other=0;
    for(n=0;n<strlen(a);n++)
    {
        if(isalpha(a[n]))
            alpha++;else
        if(a[n]>=48&&a[n]<=57)
            num++;else
        if(a[n]==' ')
            space++;else
            other++;
    }
    printf("%d %d %d %d",num,alpha,space,other);
    return 0;
}
