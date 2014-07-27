//memset c 0 before use
int c[MAXN];

//n -> update place
//v -> update value
void update(int n, int v)
{
    for(; n <= MAXN; n += (n & -n))
        c[n] += v;
}

//get the sum from 1 to n (BIT starts from 1)
int read(int n)
{
    int sum = 0;
    for(; n > 0; n -= (n & -n))
        sum += c[n];
    return sum;
}
//if need oprate different array, use int* array

/////////////////////////////////////////////

int c[MAXX][MAXY];

//update at (x,y)
void update2D(int x, int y, int v)
{
    for(; x <= MAXX; x += (x & -x))
        for(int i = y; i <= MAXY; i += (i & -i))
            c[x][i] += v;
}

//get the sum from (1,1) to (x,y)
int read2D(int x, int y)
{
    int sum = 0;
    for(; x > 0; x -= (x & -x))
        for(int i = y; i > 0; i -= (i & -i))
            sum += c[x][i];
    return sum;
}
