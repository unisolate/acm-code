#include <stdio.h>
int main()
{
    int n,i,a,b,c,d,j,m,x,y,z,bol=0;
    scanf("%d",&n);
    char num[n][7];
    for (i=0;i<n;i++)
    {
        scanf("%s",num[i]);
        a=num[i][0]-48;b=num[i][2]-48;c=num[i][4]-48;d=num[i][6]-48;
        x=a*d; y=c*b; z=b*d;
        if(num[i][3]=='+')
            m=x+y;else
            m=x-y;

        if(m<0)
        {
            m=-m;
            bol=1;
        }
        for(j=m;j>1;j--)
        {
            if(m%j==0 && z%j==0)
            {
                m=m/j;z=z/j;
            }
        }
        if(bol==1)
        {
            m=-m;
            bol=0;
        }
        if(m==z || z==1 || m==0)
            printf("%d\n",m);else
            printf("%d/%d\n",m,z);
    }
    return 0;
}
