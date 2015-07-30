#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <stack>
#include <queue>
using namespace std;

int op_rank(char c) {
    switch (c) {
    case '^':
        return 6;
    case '*': case '/':
        return 5;
    case '+': case '-':
        return 4;
    case '>': case '<': case '=': case '#':
        return 3;
    case '.':
        return 2;
    case '|':
        return 1;
    }
    return 0;
}

void shunting_yard(char *p) {
    stack<char> s;
    queue<char> q;

    int len = strlen(p);
    for (int i = 0; i < len; ++i) {
        if (isdigit(p[i]) || isalpha(p[i])) {
            if (i && (isdigit(p[i - 1]) || isalpha(p[i - 1]))) {
                puts("Syntax Error!");
                return;
            }
            q.push(p[i]);
        } else if (op_rank(p[i])) {
            if (i && op_rank(p[i - 1])) {
                puts("Syntax Error!");
                return;
            }
            while (!s.empty()) {
                if (op_rank(p[i]) <= op_rank(s.top())) {
                    q.push(s.top());
                    s.pop();
                } else break;
            }
            s.push(p[i]);
        } else if (p[i] == '(') {
            s.push(p[i]);
        } else if (p[i] == ')') {
            while (!s.empty() && s.top() != '(') {
                q.push(s.top());
                s.pop();
            }
            if (!s.empty()) {
                s.pop();
            } else {
                puts("Syntax Error!");
                return;
            }
        } else {
            puts("Lexical Error!");
            return;
        }
    }
    while (!s.empty()) {
        if (s.top() == '(') {
            puts("Syntax Error!");
            return;
        }
        q.push(s.top());
        s.pop();
    }
    while (!q.empty()) {
        putchar(q.front());
        q.pop();
    }
    puts("");
}

int main() {
    char p[1024];
    while (~scanf("%s", p)) {
        shunting_yard(p);
    }
    return 0;
}