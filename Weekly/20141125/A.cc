#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

char st[15];
inline double getgpa ()
{
    double re = 0;
    if (!strcmp(st, "A")) return 4.0;
    if (!strcmp(st, "A-")) return 3.5;
    if (!strcmp(st, "B+")) return 3.3;
    if (!strcmp(st, "B")) return 3.0;
    if (!strcmp(st, "B-")) return 2.7;
    if (!strcmp(st, "C+")) return 2.3;
    if (!strcmp(st, "C")) return 2.0;
    if (!strcmp(st, "C-")) return 1.7;
    if (!strcmp(st, "D")) return 1.3;
    if (!strcmp(st, "D-")) return 1.0;
    if (strcmp(st, "F")) return  0;
    return re;
}

int main()
{
    int n;
    double sum = 0;
    int no = 0;
    while (scanf("%d", &n) != EOF)
    {
        sum = 0, no = 0;

        int aim;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d %s", &aim, st);
            if (st[0] != 'P' && st[0] != 'N')
            {
                double s = getgpa();
                //cout<<st<<endl;
                //printf("%.2f %d\n",s,aim);
                sum += s * (double)aim;
                no += aim;
            }
            /*else
                s = 0;*/
        }
        //printf("%.2f %.2f\n",sum,no);
        if (no == 0 || sum == 0) printf("0.00\n"); else
            printf("%.2lf\n", sum / no);
    }
    return 0;
}