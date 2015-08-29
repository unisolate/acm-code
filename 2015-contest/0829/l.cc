#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;

unsigned int *PM, D0, HP, HN, VP, VN, E;
unsigned int Em, Rm;
unsigned int *PMm;
char **pat;
char *pat1, *pat2, *pat3;
char *text;
char *alphbet = (char *)"ATCGN";
int sigma = 5, k, tl, pl, pat_nums = 3;

int getAlphbetIndex(const char letter) {
    int index = 5;
    switch (letter) {
        case 'A':
            index = 0;
            break;
        case 'T':
            index = 1;
            break;
        case 'C':
            index = 2;
            break;
        case 'G':
            index = 3;
            break;
        case 'N':
            index = 4;
            break;
    }
    return index;
}

void printBinary(const unsigned int n, int bit_nums) {
    for (int i = bit_nums - 1; i >= 0; i--) {
        if ((i + 1) % (2 * k + 2) == 0) {
            if ((n & (1 << i)) == 0) {
                printf(" ");
            } else {
                printf("9");
            }
        } else {
            printf("%c", n & (1 << i) ? '1' : '0');
        }
    }
    printf("\n");
}

int main() {
    pat = (char **)malloc(sizeof(char *) * pat_nums);
    PM = (unsigned int *)malloc(sizeof(unsigned int) * sigma);
    PMm = (unsigned int *)malloc(sizeof(unsigned int) * pat_nums);
    pat1 = (char *)"TACTGGACT";
    pat2 = (char *)"GAACAGTCA";
    pat3 = (char *)"GAAGGGAGA";
    pat[0] = pat1;
    pat[1] = pat2;
    pat[2] = pat3;
    text = (char *)"CTGGA";
    k = 2;
    Em = 0;
    Rm = 0;
    for (int i = 0; i < pat_nums; i++) {
        Em = Em + (1 << (i * (2 * k + 2)));
        PMm[i] = 1 << ((2 * k) + (2 * k + 2) * i);
        printf("PMm:");
        printBinary(PMm[i], (2 * k + 2) * pat_nums);
    }
    for (int j = 0; j < pat_nums; j++) {
        Rm = Rm << 1;
        for (int i = 0; i < 2 * k + 1; i++) {
            Rm = Rm << 1;
            Rm++;
        }
    }
    printf("RM:");
    printBinary(Rm, (2 * k + 2) * pat_nums);

    VP = 0;  // text only aligns with part of pattern
    // VP = 0xFFFFFFFF & Rm; //text aligns with pattern completely
    VN = 0;
    E = 0;

    tl = strlen(text);
    pl = strlen(pat1);
    printf("The length of pattern is %d.\n", pl);
    printf("The length of text is %d.\n", tl);
    int index = 2 * k;
    for (int i = 0; i < sigma; i++) {
        PM[i] = 0;
        for (int t = pat_nums - 1; t >= 0; t--) {
            for (int j = index; j >= 0; j--) {
                PM[i] = PM[i] << 1;
                if (pat[t][j] == alphbet[i]) {
                    PM[i]++;
                }
            }
            if (t != 0) {
                PM[i] = PM[i] << 1;
            }
        }
    }

    for (int j = 0; j < tl; j++) {
        printf("j:%d\n", j);

        int tmpPM = PM[getAlphbetIndex(text[j])];
        printf("PM:");
        printBinary(tmpPM, (2 * k + 2) * pat_nums);

        D0 = ((((tmpPM & VP) + VP) ^ VP) | tmpPM | VN) & Rm;
        printf("D0:");
        printBinary(D0, (2 * k + 2) * pat_nums);

        HP = VN | ~(D0 | VP);
        printf("HP:");
        printBinary(HP, (2 * k + 2) * pat_nums);

        HN = D0 & VP;
        printf("HN:");
        printBinary(HN, (2 * k + 2) * pat_nums);

        // Update the appropriate cell value at the lower boundary
        E += Em - (D0 & Em);

        unsigned int X = (D0 >> 1) & Rm;

        VP = HN | ~(X | HP);
        printf("VP:");
        printBinary(VP, (2 * k + 2) * pat_nums);

        VN = X & HP;
        printf("VN:");
        printBinary(VN, (2 * k + 2) * pat_nums);

        index++;
        // Build the correct match vector into PM
        for (int i = 0; i < sigma; i++) {
            PM[i] = (PM[i] >> 1) & Rm;
            for (int t = 0; t < pat_nums; t++) {
                if (index < pl && pat[t][index] == alphbet[i]) {
                    PM[i] = PM[i] | PMm[t];
                }
            }
        }
    }

    printBinary(E, (2 * k + 2) * pat_nums);

    return 0;
}

// PMm: 00000 00000 10000
// PMm: 00000 10000 00000
// PMm: 10000 00000 00000
// RM: 11111 11111 11111
// The length of pattern is 9.
// The length of text is 5.
// j:0
// PM: 00000 01000 00100
// D0: 00000 01000 00100
// HP:911111910111911011
// HN: 00000 00000 00000
// VP: 00000 01000 00100
// VN: 00000 00100 00010
// j:1
// PM: 00000 00000 00100
// D0: 00000 00100 01110
// HP:911111910111910011
// HN: 00000 00000 00100
// VP: 00000 01000 01100
// VN: 00000 00010 00011
// j:2
// PM: 01110 01000 01100
// D0: 01110 11010 11111
// HP:910001900111900011
// HN: 00000 01000 01100
// VP: 01000 11000 11100
// VN: 00001 00101 00011
// j:3
// PM: 10111 00100 00110
// D0: 10111 00101 11111
// HP:900001900111900011
// HN: 00000 00000 11100
// VP: 10100 11000 11100
// VN: 00001 00010 00011
// j:4
// PM: 10100 10001 00100
// D0: 11101 10011 11111
// HP:900011900110900011
// HN: 10100 10000 11100
// VP: 10100 10000 11100
// VN: 00010 00000 00011
// 00011 00011 00010