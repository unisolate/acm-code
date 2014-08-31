#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <queue>
using namespace std;
char s[22222], u[22222], v[22222], w[22222], c;
queue<string> q;
map<string, int> m;
bool fuck()
{
    if (!q.empty())
    {
    	printf("#\n");
        int x = 0, y = 0;
        while (!q.empty())
        {
            int t = m[q.front()];
            if (t >= 1000)
                x += y * t, y = 0;
            else if (t == 100)
                y *= t;
            else if (t > 0)
                y += t;
            q.pop();
        }
        printf("%d", x + y);
        return true;
    }
    return false;
}
int main()
{
    m["zero"] = -1;
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;
    m["four"] = 4;
    m["five"] = 5;
    m["six"] = 6;
    m["seven"] = 7;
    m["eight"] = 8;
    m["nine"] = 9;
    m["ten"] = 10;
    m["eleven"] = 11;
    m["twelve"] = 12;
    m["thirteen"] = 13;
    m["fourteen"] = 14;
    m["fifteen"] = 15;
    m["sixteen"] = 16;
    m["seventeen"] = 17;
    m["eighteen"] = 18;
    m["nineteen"] = 19;
    m["twenty"] = 20;
    m["thirty"] = 30;
    m["forty"] = 40;
    m["fifty"] = 50;
    m["sixty"] = 60;
    m["seventy"] = 70;
    m["eighty"] = 80;
    m["ninety"] = 90;
    m["hundred"] = 100;
    m["thousand"] = 1000;
    m["million"] = 1000000;
    m["and"] = -2;
    queue<string> q;
    while (~scanf("%s", s))
    {
        scanf("%c", &c);
        strcpy(u, s);
        strcpy(v, s);
        v[0] = tolower(v[0]);
        strcpy(w, v);
        char t1 = u[strlen(u) - 1];
        if (t1 == ',' || t1 == '.' || t1 == '!' || t1 == '?' || t1 == ':' || t1 == ';' || t1 == '(' || t1 == ')')
            u[strlen(u) - 1] = '\0', w[strlen(w) - 1] = '\0';
        if (m[s] > 0) q.push(s);
        else if (m[s] == -1) fuck(), printf(" 0%c", c);
        else if (!q.empty() && m[s] == -2) q.push(s);
        else if (m[v] > 0) q.push(v);
        else if (m[v] == -1) fuck(), printf(" 0%c", c);
        else if (!q.empty() && m[v] == -2) q.push(v);
        else if (m[u] > 0) q.push(u), fuck();
        else if (m[u] == -1) fuck(), printf(" 0%c", c);
        else if (m[u] == -2) fuck(), q.push(u);
        else if (m[w] > 0) q.push(w), fuck();
        else if (m[w] == -1) fuck(), printf(" 0%c", c);
        else if (m[w] == -2) fuck(), q.push(w);
        else {
            if (fuck()) printf(" "); printf("%s%c", s, c);
        }
        // else if (m[v] > 0) q.push(v);
        // else if (m[u] > 0 || m[u] == -1)
        // {
        //     q.push(u);
        //     fuck();
        //     printf("%c ", t1);
        // }
        // else
        // {

        // }
        // else
        // {
        //     fuck(); putchar(' ');
        //     printf("%s%c", s, c);
        // }
    }
    return 0;
}

/*

From three thousand one hundred and fifty teams selected
from one thousand four hundred and eleven universities
in seventy five countries competing at one hundred and
twenty seven sites and hundreds more competing at
preliminary contests worldwide, seventy three teams
of students competed for bragging rights and prizes
at The Twenty Eighth Annual ACM International Collegiate
Programming Contest World Finals sponsored by IBM on
March Thirty One, Two Thousand Four, and hosted at the
Obecni Dum, Prague by Czech Technical University in Prague.


From 3150 teams selected
from 1411 universities
in 75 countries competing at 127 sites and hundreds more competing at
preliminary contests worldwide, 73 teams
of students competed for bragging rights and prizes
at The 20 Eighth Annual ACM International Collegiate
Programming Contest World Finals sponsored by IBM on
March 31, 2004, and hosted at the
Obecni Dum, Prague by Czech Technical University in Prague.

*/