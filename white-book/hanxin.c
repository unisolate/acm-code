#include <stdio.h>
int main()
{
    int num,n1,n2,n3;
    scanf ("%d %d %d",&n1,&n2,&n3);
    for (num=10;num<=100;num++)
    {
        if (num%3==n1 && num%5==n2 && num%7==n3)
        {
            printf ("%d",num);
            break;
        }

    }
    if (num==101)
        printf ("No Answer");
}
//NO Answer 怎么加入值得思考。
