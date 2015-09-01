#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
struct Node {
    ll a, b;
    struct Node *next;
};
typedef struct Node Node;
int main() {
    int n, t;
    ll x, y;
    while (scanf("%d", &n) && n) {
        Node *head = NULL;
        while (n--) {
            scanf("%d%lld%lld", &t, &x, &y);
            if (t == 1) {
                Node *tmp = (Node *)malloc(sizeof(Node));
                tmp->a = x, tmp->b = y, tmp->next = head;
                head = tmp;
            } else if (t == 0) {
                Node *i = head;
                ll ans = (i->a) * x + (i->b) * y;
                while (i != NULL) {
                    if ((i->a) * x + (i->b) * y > ans) {
                        ans = (i->a) * x + (i->b) * y;
                    }
                    i = i->next;
                }
                printf("%lld\n", ans);
            } else {
                Node *i = head;
                if (i != NULL) {
                    Node *j = i->next;
                    if ((i->a) == x && (i->b) == y) {
                        free(i);
                        head = j;
                    } else {
                        while (j != NULL) {
                            if ((j->a) == x && (j->b) == y) {
                                i->next = j->next;
                                free(j);
                                break;
                            }
                            i = j;
                            j = j->next;
                        }
                    }
                }
            }
        }
    }
    return 0;
}