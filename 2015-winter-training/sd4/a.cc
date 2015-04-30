#include <cstdio>
#include <cmath>
using namespace std;
double x, y, x2, y2, x3, y3, mx, my;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%lf%lf%lf%lf", &x2, &y2, &x3, &y3);
        mx = (x2 + x3) / 2;
        my = (y2 + y3) / 2;
        
        printf("(%.2lf,%.2lf)\n", x, y);
    }
    return 0;
}