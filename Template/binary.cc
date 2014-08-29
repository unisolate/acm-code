int l = MIN, r = MAX, p = (l + r) >> 1;
while (l <= r)
{
    if (arr[p] == k)
    {
        cout << p << endl;
        return;
    }
    if (arr[p] < k)
        l = p + 1;
    else if (arr[p] > k)
        r = p - 1;
    p = (l + r) >> 1;
}
cout << "No solution" << endl;