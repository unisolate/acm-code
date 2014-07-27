#include <stdio.h>
int main(void)
{
    char letter;
    printf ("Please enter a letter.");
    scanf ("%c",&letter);

    char n,n1,space,up,down;
    for (n='A',n1=1;n<=letter;n++,n1++)
    {
        for (up=1;up<=letter-n;up++)
            printf (" ");
        for (up=0;up<n1;up++)
            printf ("%c",'A'+up);
        for (down=0;down<n1-1;down++)
            printf ("%c",'A'+up-down-2);
        printf ("\n");
    }

    return 0;
}
