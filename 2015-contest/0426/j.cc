#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <map>
using namespace std;
char s;
int main() {
    map<char, char> m;
    m['q'] = '\'';
    m['Q'] = '\"';
    m['w'] = ',';
    m['W'] = '<';
    m['e'] = '.';
    m['E'] = '>';
    m['r'] = 'p';
    m['R'] = 'P';
    m['t'] = 'y';
    m['T'] = 'Y';
    m['y'] = 'f';
    m['Y'] = 'F';
    m['u'] = 'g';
    m['U'] = 'G';
    m['i'] = 'c';
    m['I'] = 'C';
    m['o'] = 'r';
    m['O'] = 'R';
    m['p'] = 'l';
    m['P'] = 'L';
    m['['] = '/';
    m['{'] = '?';
    m[']'] = '=';
    m['}'] = '+';
    m['\\'] = '\\';
    m['|'] = '|';
    m['`'] = '`';
    m['~'] = '~';
    m['-'] = '[';
    m['_'] = '{';
    m['='] = ']';
    m['+'] = '}';
    m['a'] = 'a';
    m['A'] = 'A';
    m['s'] = 'o';
    m['S'] = 'O';
    m['d'] = 'e';
    m['D'] = 'E';
    m['f'] = 'u';
    m['F'] = 'U';
    m['g'] = 'i';
    m['G'] = 'I';
    m['h'] = 'd';
    m['H'] = 'D';
    m['j'] = 'h';
    m['J'] = 'H';
    m['k'] = 't';
    m['K'] = 'T';
    m['l'] = 'n';
    m['L'] = 'N';
    m[';'] = 's';
    m[':'] = 'S';
    m['\''] = '-';
    m['\"'] = '_';
    m['z'] = ';';
    m['Z'] = ':';
    m['x'] = 'q';
    m['X'] = 'Q';
    m['c'] = 'j';
    m['C'] = 'J';
    m['v'] = 'k';
    m['V'] = 'K';
    m['b'] = 'x';
    m['B'] = 'X';
    m['n'] = 'b';
    m['N'] = 'B';
    m['m'] = 'm';
    m['M'] = 'M';
    m[','] = 'w';
    m['<'] = 'W';
    m['.'] = 'v';
    m['>'] = 'V';
    m['/'] = 'z';
    m['?'] = 'Z';
    while ((s = getchar()) != EOF) {
        if (isprint(s)) {
            printf("%c", m[s] ? m[s] : s);
        } else printf("%c", s);
    }
    return 0;
}