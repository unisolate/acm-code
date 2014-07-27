#define RATE1 0.15
#define RATE2 0.28
#define RANK1 17850
#define RANK2 23900
#define RANK3 29750
#define RANK4 14875
#include <stdio.h>
int main (void)
{
    char ch;
    float income,tax;

    printf ("*****************************************\n");
    printf ("1988 United States Federal TAx Schedule:\n");
    printf ("a)Single               b)Household\n");
    printf ("c)Married              d)Divorced\n");
    printf ("q)Quit\n");
    printf ("******************************************\n");

    while ((ch = getchar()) != 'q')
    {
        switch (ch)
    {
        case 'a':printf ("Please enter your income:");
        scanf ("%f",&income);
        if (income<RANK1)
            tax = income*RATE1;
        else
            tax = RANK1*RATE1+RATE2*(income-RANK1);
        printf ("The tax you need to pay is $%f.\n",tax);
        break;

        case 'b':printf ("Please enter your income:");
        scanf ("%f",&income);
        if (income<RANK2)
            tax = income*RATE1;
        else
            tax = RANK2*RATE1+RATE2*(income-RANK2);
        printf ("The tax you need to pay is $%f.\n",tax);
        break;

        case 'c':printf ("Please enter your income:");
        scanf ("%f",&income);
        if (income<RANK3)
            tax = income*RATE1;
        else
            tax = RANK3*RATE1+RATE2*(income-RANK3);
        printf ("The tax you need to pay is $%f.\n",tax);
        break;

        case 'd':printf ("Please enter your income:");
        scanf ("%f",&income);
        if (income<RANK4)
            tax = income*RATE1;
        else
            tax = RANK4*RATE1+RATE2*(income-RANK4);
        printf ("The tax you need to pay is $%f.\n",tax);
        break;
    }

    }
    printf ("Bye!");


    return 0;
}
