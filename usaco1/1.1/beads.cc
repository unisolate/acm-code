/*
ID: unisola1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 400;
int main()
{
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    int n, maxx = 0;
    char line[maxn];
    cin >> n >> line;
    for (int i = 0; i < n; ++i)
    {
        int j = i, temp = 0;
        char front = line[i];
        while (line[j] == front || line[j] == 'w')
        {
            temp++;
            j++;
            if (front == 'w')
                front = line[j];
            if (j >= n)
                j = 0;
            if (temp >= n)
                break;
        }
        if (temp >= n)
        {
            maxx = n;
            break;
        }
        j = i - 1;
        if (j < 0)
            j = n - 1;
        char back = line[j];
        while (line[j] == back || line[j] == 'w')
        {
            temp++;
            j--;
            if (front == 'w')
                front = line[j];
            if (j < 0)
                j = n - 1;
        }
        if (temp >= n)
        {
            maxx = n;
            break;
        }
        if (maxx < temp)
            maxx = temp;
    }
    cout << maxx << endl;
    return 0;
}