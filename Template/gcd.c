//求gcd

//Euclid算法
int gcd(int a, int b)
{
    return (b ? gcd(b, a % b) : a);
}


int gcd(int a, int b)
{
    int t;
    while(b)
    {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

//二进制算法  适合大数

int gcd(int a, int b)
{
    int t = 1, c, d;
    while(a != b)
    {
        if(a < b) swap(a, b);
        if(!(a & 1))
        {
            a >>= 1;
            c = 1;
        }
        else c = 0;
        if(!(b & 1))
        {
            b >>= 1;
            d = 1;
        }
        else d = 0;
        if(c && d) t <<= 1;
        else if(!c && !d) a -= b;
    }
    return t * a;
}
