#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mes[1000][2];
int comp ( const void *a, const void *b )
{
    return * ( int * ) a - * ( int * ) b;
}
int main()
{
    char s[10];
    int n=0,k=0,t=0,i,j;
    while(scanf("%s",s) && s[0]!='#')
    {
        scanf("%d %d",&mes[n][0],&mes[n][1]);
        n++;
    }
    qsort(mes,n,sizeof(mes[0]),comp);
    scanf("%d",&k);
    for(i=1;t!=k;i++)
    {
        for(j=0;j<n&&t!=k;j++)
        {
            if(i%mes[j][1]==0)
            {
                printf("%d\n",mes[j][0]);
                t++;
            }
        }
    }
    return 0;
}