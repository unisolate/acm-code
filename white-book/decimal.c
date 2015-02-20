#include <stdio.h>
int main()
{
    int a,b,c;
    scanf ("%d %d %d",&a,&b,&c);
    printf ("%.5f",(float) (a/b));
    return 0;
}

//This problem is so HARD T.T
/*

#include <stdio.h>
#include <math.h>
int main()
{
 int a,b,c;
 scanf("%d%d%d",&a,&b,&c);
 printf("%d.",a/b);
 a=a%b*10;
 int d=1,x;
 while(d<=c)
 {
  x=a/b;
  if(d==c) printf("%d",(a%b*10)/b>=5?x+1:x);  //注意末位四舍五入
  else printf("%d",x);
  a=a%b*10;
  d++;
 }
 return 0;
}


*/
