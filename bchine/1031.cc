#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int t;
    cin >> t;
    bool flag = true;
    while (t--)
    {
        int num[222], maxx = 0;
        memset(num, 0, sizeof(num));
        char temp[100];
        if (flag)
            getchar();
        flag = false;
        for (int i = 0; i < 4; ++i)
        {
            gets(temp);
            for (int j = 0; j < strlen(temp); ++j)
                num[temp[j]]++;
        }
        for (int i = 'A'; i <= 'Z'; ++i)
        {
            if (num[i] > maxx)
                maxx = num[i];
        }
        int top = maxx;
        for (int k = 0; k < maxx; ++k)
        {
            int left = 0;
            for (int i = 'A'; i <= 'Z'; ++i)
                if (num[i] >= top)
                    left = i;
            for (int i = 'A'; i <= left; ++i)
            {
                if (num[i] >= top)
                    cout << "*";
                else cout << " ";
                if (i == left)
                    cout << endl;
                else cout << " ";
            }
            top--;
        }
        for (int i = 'A'; i <= 'Z'; ++i)
        {
            printf("%c", i);
            if (i == 'Z')
                cout << endl;
            else cout << " ";
        }
    }
    return 0;
}