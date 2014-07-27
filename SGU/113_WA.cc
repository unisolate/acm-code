#include <iostream>
#include <cmath>
#define N 500000000
using namespace std;
int sieve[(N >> 6) + 1];

int GET(int x)
{
    return sieve[x >> 5] >> (x & 31) & 1;
}
void SET(int x)
{
    sieve[x >> 5] |= 1 << (x & 31);
}

#define N2I(i) (((i)-1)>>1)
#define I2N(i) (((i)<<1)+1)

bool isprime(int x)
{
    return x == 2 || x > 2 && (x & 1) && !GET(N2I(x));
}

void findprime()
{
    int half_sqrt_N = sqrt(N) / 2;
    register int i, j, k, ii;
    for (i = 1; i <= half_sqrt_N; i++)
        if (!GET(i))
            for (ii = I2N(i), j = N2I(N / ii), k = ii * j + i; j >= i; j--, k -= ii)
                if (!GET(j))
                    SET(k);
}
int main()
{
    findprime();
    int n, x;
    cin >> n;
    while (n--)
    {
        cin >> x;
        bool flag = true;
        for (int i = 2; i < x; ++i)
        {
            if (isprime(i) && (x % i) == 0 && isprime(x / i))
            {
                cout << "Yes" << endl;
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "No" << endl;
    }
    return 0;
}

