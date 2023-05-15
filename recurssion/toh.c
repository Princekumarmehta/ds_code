#include <stdio.h>

int count = 1;
void toh(int n, char s, char t, char d)
{
    if (n > 0)
    {
        toh(n - 1, s, d, t);
        printf(" %d. Move %d disc from %c to %c\n", count++, n, s, d);
        toh(n - 1, t, s, d);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    toh(n, 's', 't', 'd');
    return 0;
}