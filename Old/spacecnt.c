#include <stdio.h>
#include <ctype.h>
#define STOP '#'
int main (void)
{
    char c;
    int space=0,line=0,chars=0;
    while ((c=getchar()) != STOP)
    {
        chars++;
        if(isspace(c))
            space++;
        if(c=='\n')
            line++;
    }
    printf ("char=%d,space=%d,line=%d",chars,space,line);
    return 0;
}
