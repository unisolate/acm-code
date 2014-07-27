//未AC，试过无数样例始终找不到问题。

#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j;
    char ans[1000],guess[1000];
    while(scanf("%d",&n))
    {
        if(n==-1)
            break;
        int fail=0,cou=0,pass=0,same=0;
        scanf("%s %s",ans,guess);
        printf("Round %d\n",n);
        for(i=0;i<strlen(guess);i++)
        {
            int right=0;
            for(j=0;j<i;j++)
                if(guess[i]==guess[j])
                    same=1;
            for(j=0;j<strlen(ans);j++)
            {
                if(guess[i]==ans[j])
                {
                    ans[j]='#';
                    right=1;
                }
            }
            if(right==0 && same==0)
                fail++;else
            if(right==1)
                pass++;
            if(pass>=strlen(ans))
                break;
            same=0;
        }
        for(i=0;i<strlen(ans);i++)
            if(ans[i]=='#' && fail<7)
                cou++;
        if(cou==strlen(ans))
            printf("You win.\n");else
        if(fail<7)
            printf("You chickened out.\n");else
        if(fail>=7)
            printf("You lose.\n");
        n++;
    }
    return 0;
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
     int i,R,ct,sum;
     char s[80];
     int index[26];
     while(scanf("%d",&R),R!=-1)
     {
         memset(index,0,sizeof(index));
         scanf("%s",s);
         sum=0;
         for(i=0;s[i]>='a'&&s[i]<='z';i++)
              if(index[s[i]-'a']==0)      //index记录了字母是否出现,sum记录字母种类个数
                   index[s[i]-'a']=1,sum++;
         scanf("%s",s);
         ct=0;
         for(i=0;s[i]>='a'&&s[i]<='z';i++)
         {
              if(index[s[i]-'a']==1)      //这里隐式表达了,猜出同样的字母算失败
                   index[s[i]-'a']=0,sum--;
              else
                   ct++;
              if(sum==0 || ct==7)
                   break;
         }
         printf("Round %d\n",R);
         if(sum==0)
              printf("You win.\n");
         else if(ct==7)
              printf("You lose.\n");
         else
              printf("You chickened out.\n");
     }
     return 0;
}

*/
