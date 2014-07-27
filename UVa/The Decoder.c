#include <stdio.h>
#include <string.h>
int main()
{
    char sen[500];
    int n;
    while (scanf ("%s",sen)==1)
    {
        for (n=0;n<strlen(sen);n++)
            printf("%c",sen[n]-7);
        printf ("\n");
    }

    return 0;
}
