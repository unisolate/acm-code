#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    srand(time(0));
    int n = rand() % 10 + 2;
    printf("%d\n", n);
    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", rand() % 997 + 2, rand() % 997 + 2);
    }
    return 0;
}