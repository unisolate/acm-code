/*
INFO : 228 KB	0 ms	GNU C++	1646 B	2014-04-26 21:53:50
华容道,四种类型的方块求可能的放置方案数
DFS可解
很久之前的遗留题目,卡了很久,搜索好难...
*/
#include <iostream>
#include <cstring>
using namespace std;
int n, m = 4;
bool b;
int block[5][5], s;  //2x2、2x1、1x2、1x1

void dfs(int sum)
{
    if (b && sum == n * m)
    {
        s++;
        return;
    }
    if (sum >= n * m)
    	return;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!b && (i + 1 < n) && (j + 1 < m) && !block[i][j] && !block[i + 1][j + 1] && !block[i + 1][j] && !block[i][j + 1])
            {
                block[i][j] = block[i + 1][j] = block[i][j + 1] = block[i + 1][j + 1] = 1;
                b = true;
                dfs(sum + 4);
                block[i][j] = block[i + 1][j] = block[i][j + 1] = block[i + 1][j + 1] = 0;
                b = false;
            }
            if ((i + 1 < n) && (j < m) && !block[i][j] && !block[i + 1][j])
            {
                block[i + 1][j] = block[i][j] = 1;
                dfs(sum + 2);
                block[i][j] = block[i + 1][j] = 0;
            }
            if ((i < n) && (j + 1 < m) && !block[i][j] && !block[i][j + 1])
            {
                block[i][j] = block[i][j + 1] = 1;
                dfs(sum + 2);
                block[i][j] = block[i][j + 1] = 0;
            }
            if (!block[i][j])
            {
                block[i][j] = 1;
                dfs(sum + 1);
                block[i][j] = 0;
                return;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(block, 0, sizeof(block));
        b = false;
        s = 0;
        dfs(0);
        cout << s << endl;
    }
    return 0;
}