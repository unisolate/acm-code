#include<stdio.h>
#include<string.h>
int main()
{
    char sen[100][100];
    int n=0,i=0,j=0,m=0;
    memset(sen,0,sizeof(sen));

    for(n=0;n<100;n++)
    {
        gets(sen[n]);
        if (sen[n][strlen(sen[n])]==EOF)
            break;
    }

    for(i=0;i<=n;i++)
    {
        if(m<strlen(sen[i]))
            m=strlen(sen[i]);
    }

    for(j=0;j<100;j++)
    {
        if(j>=m)
            break;
        for(i=n-1;i>=0;--i)
        {
            if(j<strlen(sen[i]) && i>0)
                printf("%c",sen[i][j]);else
            if(j<strlen(sen[i]) && i==0)
                printf("%c\n",sen[i][j]);else
            if(j>=strlen(sen[i]) && i>0)
                printf(" ");else
            if(j>=strlen(sen[i]) && i==0)
                printf(" \n");
        }
    }

    return 0;
}
