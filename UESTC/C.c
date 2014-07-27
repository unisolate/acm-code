#include<stdio.h>
#include<string.h>
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        int m,n,j;
        printf("Case #%d:\n",i);
        scanf("%d %d",&n,&m);
        int atk[n+1],def[n+1];
        memset(atk,0,sizeof(atk));
        memset(def,0,sizeof(def));
        for(j=0;j<m;j++)
        {
            char a,b;
            int x,y;
            getchar();
            scanf("%c",&a);
            if(a=='K')
            {
                int far;
                scanf("%d %d",&x,&y);
                if(y>x)
                    far=y-x;else
                    far=x-y;
                if(n-far<far)
                    far=n-far;
                if(far-atk[x]+def[y]<=1)
                    printf("Yes!\n");else
                    printf("I'm sorry.\n");
            }else
            {
                x=a-48;
                getchar();
                scanf("%c%d",&b,&y);
                if(b=='+')
                    def[x]+=y;else
                    atk[x]+=y;
            }
        }
        if(i!=t)
            printf("\n");
    }
    return 0;
}
