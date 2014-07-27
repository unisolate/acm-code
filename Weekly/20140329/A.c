#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1001
using namespace std;
bool prime[10000];
void findprime()
{
    for (int i = 0; i < 10000; i++)
        prime[i] = true;
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i < 10000; i++)
        if (prime[i])
            for (int j = i * i; j < 10000; j += i)
                prime[j] = false;
}
double maxx(double a, double b)
{
    return a > b ? a : b;
}
struct app
{
    char name[50], team[50], sex[1];
    double score;
} p[MAXN];
struct team
{
    string name;
    int rank;
} tt[MAXN];
int cmp(struct app a, struct app b)
{
    if(a.score!=b.score)
        return a.score > b.score;
    else return !strcmp(a.name,b.name);
}
int cmp1(int a, int b)
{
    return a > b;
}
int main()
{
    int t;
    cin >> t;
    findprime();
    while (t--)
    {
        int n, m, r, q, s, pp, c, rr[MAXN], ss[MAXN];
        cin >> n >> m;
        cin >> r;
        for (int i = 0; i < r; ++i)
        {
            cin >> rr[i];
        }
        cin >> s;
        for (int i = 0; i < s; ++i)
        {
            cin >> ss[i];
        }
        cin >> q;
        for (int i = 0; i < q; ++i)
        {
            cin >> tt[i].name >> tt[i].rank;
        }
        for (int i = 0; i < n; ++i)
        {
            int temp;
            p[i].score = 0;
            cin >> p[i].name >> p[i].team >> p[i].sex >> pp >> c;
            if (p[i].sex == "F")
                p[i].score += 33;
            for (int j = 0; j < q; ++j)
            {
                if (p[i].team == tt[j].name)
                {
                    if (tt[j].rank == 1)
                        p[i].score += 36;
                    else if (tt[j].rank == 2)
                        p[i].score += 27;
                    else if (tt[j].rank == 3)
                        p[i].score += 18;
                    break;
                }
            }
            for (int j = 0; j < pp; ++j)
            {
                cin >> temp;
                bool flag = true;
                for (int z = 0; z < r; ++z)
                {
                    if (temp == rr[z])
                    {
                        p[i].score += 2.5;
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    for (int z = 0; z < s; ++z)
                    {
                        if (temp == ss[z])
                        {
                            p[i].score += 1.5;
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag)
                {
                    if (prime[temp])
                    {
                        p[i].score += 1.0;
                        flag = false;
                    }
                }
                if (flag)
                {
                    p[i].score += 0.3;
                }
            }
            int nnn[c];
            for (int j = 0; j < c; ++j)
            {
                cin >> nnn[j];
            }
            sort(nnn, nnn + c, cmp1);
            if (c > 3)
                p[i].score += maxx(0, (double)((nnn[2] - 1200) / 100) * 1.5);
        }
        sort(p, p + MAXN, cmp);
        for (int i = 0; i < m; ++i)
        {
            cout << p[i].name << " ";
            printf("%.3f\n", p[i].score);
        }
    }
    return 0;
}