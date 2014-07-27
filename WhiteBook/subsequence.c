#include <stdio.h>
int main()
{
    float n,m,sum;
    scanf ("%f %f",&n,&m);
    for (;n<=m;n++)
        sum += 1/(n*n);
    printf ("%.5f",sum);
    return 0;
}

//where's the trap?
