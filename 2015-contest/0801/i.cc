#include <cstdio>
#include <algorithm>
using namespace std;
struct Node {
    Node *pre, *next;
    int v;
} p[1000010];
int main() {
    int t, n, m, l, r;
    char o[99];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        p[0].pre = NULL; p[0].next = &p[1];
        p[n + 1].pre = &p[n], p[n + 1].next = NULL;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &p[i].v);
            p[i].pre = &p[i - 1];
            p[i].next = &p[i + 1];
        }
        scanf("%d%d%d", &l, &r, &m);
        Node *L = &p[l], *R = &p[r];
        Node *LL = L->pre, *RR = R->next;
        int k = n + 2;
        while (m--) {
            scanf("%s", o);
            if (o[0] == 'M' && o[4] == 'L') {
                scanf("%s", o);
                if (o[0] == 'L') {
                    if (LL->pre == L) {
                        L = LL;
                        LL = L->next;
                    } else {
                        L = LL;
                        LL = L->pre;
                    }
                } else {
                    if (R->pre == RR) {
                        RR = R;
                        R = R->next;
                    } else {
                        RR = R;
                        R = R->pre;
                    }
                }
            } else if (o[0] == 'M' && o[4] == 'R') {
                scanf("%s", o);
                if (o[0] == 'L') {
                    if (L->pre == LL) {
                        LL = L;
                        L = L->next;
                    } else {
                        LL = L;
                        L = L->pre;
                    }
                } else {
                    if (RR->pre == R) {
                        R = RR;
                        RR = R->next;
                    } else {
                        R = RR;
                        RR = R->pre;
                    }
                }
            } else if (o[0] == 'I') {
                scanf("%s%d", o, &p[k].v);
                if (o[0] == 'L') {
                    p[k].pre = LL;
                    p[k].next = L;
                    if (LL->pre == L)
                        LL->pre = &p[k];
                    else LL->next = &p[k];
                    if (L->pre == LL)
                        L->pre = &p[k];
                    else L->next = &p[k];
                    L = &p[k++];
                } else {
                    p[k].pre = RR;
                    p[k].next = R;
                    if (RR->pre == R)
                        RR->pre = &p[k];
                    else RR->next = &p[k];
                    if (R->pre == RR)
                        R->pre = &p[k];
                    else R->next = &p[k];
                    R = &p[k++];
                }
            } else if (o[0] == 'D') {
                scanf("%s", o);
                Node *u;
                if (o[0] == 'L') {
                    if (L->pre == LL)
                        u = L->next;
                    else u = L->pre;
                    if (LL->pre == L)
                        LL->pre = u;
                    else LL->next = u;
                    if (u->pre == L)
                        u->pre = LL;
                    else u->next = LL;
                    L = u;
                } else {
                    if (R->pre == RR)
                        u = R->next;
                    else u = R->pre;
                    if (RR->pre == R)
                        RR->pre = u;
                    else RR->next = u;
                    if (u->pre == R)
                        u->pre = RR;
                    else u->next = RR;
                    R = u;
                }
            } else {
                if (R->pre == RR)
                    R->pre = LL;
                else R->next = LL;
                if (L->pre == LL)
                    L->pre = RR;
                else L->next = RR;
                if (LL->pre == L)
                    LL->pre = R;
                else LL->next = R;
                if (RR->pre == R)
                    RR->pre = L;
                else RR->next = L;
                swap(L, R);
            }
        }
        Node *a = p[0].next, *b = &p[0];
        bool f = false;
        while (a != &p[n + 1]) {
            if (f)
                printf(" %d", a->v);
            else printf("%d", a->v), f = true;
            if (a->next == b) {
                b = a;
                a = a->pre;
            } else {
                b = a;
                a = a->next;
            }
        }
        puts("");
    }
    return 0;
}