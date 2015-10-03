#include<iostream>
#define REP(i,n) for(int i=0;i<n;i++)
#define Renew(x,c)x=max(x,c)
using namespace std;
typedef long long LL;
const int maxn = 60000, maxv = maxn * 4, inf = ~0U >> 2;
int A[maxn], n;
struct Tree
{
    LL Max, Lmax, Rmax, Sum;
    Tree() {} Tree(int M, int L, int R, int S): Max(M), Lmax(L), Rmax(R), Sum(S)
    {
        Lch = Rch = 0;
    }
    Tree *Lch, *Rch;
} *root;
inline void Update(Tree *F, Tree *Lch, Tree *Rch)
{
    F->Sum = Lch->Sum + Rch->Sum;
    F->Lmax = max(Lch->Lmax, Lch->Sum + Rch->Lmax);
    F->Rmax = max(Rch->Rmax, Rch->Sum + Lch->Rmax);
    F->Max = max(max(Lch->Max, Rch->Max), Lch->Rmax + Rch->Lmax);
}
Tree *build(int l, int r)
{
    if (l == r) return new Tree(A[l], A[l], A[l], A[l]);
    Tree *now = new Tree; int mid = (l + r) / 2; now->Lch = build(l, mid); now->Rch = build(mid + 1, r); Update(now, now->Lch, now->Rch); return now;
} Tree *ask(Tree *T, int l, int r, int first, int last)
{
    if (l == first && r == last) return T;
    int mid = (l + r) / 2;
    if (first > mid) return ask(T->Rch, mid + 1, r, first, last);
    if (last <= mid) return ask(T->Lch, l, mid, first, last);
    Tree *ans = new Tree;
    Update(ans, ask(T->Lch, l, mid, first, mid), ask(T->Rch, mid + 1, r, mid + 1, last));
    return ans;
} int main()
{
    cin >> n;
    REP(i, n) scanf("%d", A + i);
    root = build(0, n - 1);
    int q, s, t;
    cin >> q;
    REP(i, q)
    {
        scanf("%d %d", &s, &t);
        s = max(s, 1);
        t = min(t, n);
        printf("%lldn", ask(root, 0, n - 1, s - 1, t - 1)->Max);
    }
}