#include <iostream>
#include <algorithm>
using namespace std;

const int Maxv = 1001;
int N, V, F[Maxv];

int main()
{
    cin >> N >> V;
    for (int i = 1, w, c; i <= N; i ++)
    {
        cin >> w >> c;
        for (int j = V; j >= w; j --)
            F[j] = max(F[j], F[j - w] + c);
    }
    cout << F[V] << endl;
    return 0;
}