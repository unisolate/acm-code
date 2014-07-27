#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,a,j,k,t,m;
    scanf("%d",&n);
    char gene[n][100];
    for(i=0;i<n;i++)
        scanf("%s",gene[i]);
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        int flag;
        char people[100];
        scanf("%s",people);
        for(j=0;j<n;j++)
        {
            for(m=0;m<strlen(people);m++)
            {
                k=m;flag=0;
                while(people[k]!=gene[j][0])
                    k++;
                if(k<strlen(people)-2)
                {
                    for(t=1,flag=1;t<strlen(gene[j]);t++)
                        if(people[k+t]!=gene[j][t])
                            flag=0;
                }
                if(flag)
                    break;
            }
            if(flag)
                break;
        }
        if(flag)
            printf("A new hero discovered\n");else
            printf("Just an ordinary person\n");
    }
    return 0;
}
