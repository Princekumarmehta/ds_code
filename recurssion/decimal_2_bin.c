#include <stdio.h>

void tobin(int n)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        tobin(n / 2);
        printf("%d", n % 2);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    tobin(n);
    return 0;
}