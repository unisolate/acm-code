bool prime[MAXN];
void findprime()
{
    for (int i = 0; i < MAXN; i++)
        prime[i] = true;

    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i < MAXN; i++)
        if (prime[i])
            for (int j = i * i; j < MAXN; j += i)
                prime[j] = false;
}
int main()
{
    int i;
    findprime();
    for (i = 3; i < 100; i++)
        if (prime[i] == true)
            printf("%d\n", i);
    return 0;
}

//////////////////////////

void get_prime()
{
    int cnt = 0;
    for (int i = 2; i < N; i++)
    {
        if (!tag[i])  p[cnt++] = i;
        for (int j = 0; j < cnt && p[j] * i < N; j++)
        {
            tag[i * p[j]] = 1;
            if (i % p[j] == 0)
                break;

        }

    }
}
int phi[3000010]; //Euler Function
int euler()
{
    int i, j;
    for (i = 0; i < 3000010; i++)
        phi[i] = 0;
    for (i = 2; i < 3000010; i++)
    {
        if (!phi[i])
            for (j = i; j < 3000010; j += i)
            {
                if (!phi[j])phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
    }
}
