#include <stdio.h>
int gcd(int m, int n)
{
    if (n == 0)
        return m;
    else if (n > m)
    {
        return gcd(n, m);
    }
    else
        return gcd(n, m % n);
}

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    int res = gcd(m, n);
    printf("\ngcd is %d", res);
    return 0;
}