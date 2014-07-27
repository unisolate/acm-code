#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char line[222222];
bool ha[222222];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(ha, false, sizeof(ha));
        cin >> line;
        int len = strlen(line);
        bool flag = true;
        while (flag)
        {
            flag = false;
            int pre = 0;
            for (int i = 1; i < len; ++i)
            {
                while (ha[pre])
                    pre++;
                i = pre + 1;
                while (ha[i])
                    i++;
                if (i >= len)
                    break;
                if (line[i] == line[pre])
                {
                    ha[i] = true;
                    ha[pre] = true;
                    flag = true;
                }
                else
                {
                    pre = i;
                }
            }
        }
        for (int i = 0; i < len; ++i)
            if (!ha[i])
                cout << line[i];
        cout << endl;
    }
    return 0;
}