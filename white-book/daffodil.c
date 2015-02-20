#include <stdio.h>
#include <math.h>
int main()
{
    int num,one,two,three;
    for (num=100;num<1000;num++)
    {
        one=num/100;two=(num%100)/10;three=num%10;
        if ( (int)pow(one,3) + (int)pow(two,3) + (int)pow(three,3) == num)
            printf ("%d\n",num);
    }
    return 0;
}

/*

#include <stdio.h>
int main()
{
    int num,one,two,three;
    for (num=100;num<1000;num++)
    {
        one=num/100;two=(num%100)/10;three=num%10;
        if (one*one*one+two*two*two+three*three*three == num)
            printf ("%d\n",num);
    }
    return 0;
}



*/
