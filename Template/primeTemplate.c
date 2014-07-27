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