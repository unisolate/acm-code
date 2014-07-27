#include <stdio.h>
int main()
{
    int i,k,n1,n2,n3,n[9];
    for (n1=100;n1<333;n1++)
    {
        n2=n1*2;n3=n1*3;
        n[0]=n1/100;n[1]=(n1%100)/10;n[2]=n1%10;
        n[3]=n2/100;n[4]=(n2%100)/10;n[5]=n2%10;
        n[6]=n3/100;n[7]=(n3%100)/10;n[8]=n3%10;
        for (i=0;i<9;i++)
        {
            for (k=i+1;k<9;k++)
            {
                if(n[i] != n[k] && )
                printf ("%d %d %d\n",n1,n2,n3);
                break;
            }
        }
    }
    return 0;
}

//烂尾了……我实在写不下去了……这鸟题……
