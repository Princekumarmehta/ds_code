#include <stdio.h>

int pal(int a[], int beg, int end)
{
    if (beg >= end)
    {
        return 1;
    }
    else if (a[beg] == a[end])
    {
        pal(a, beg + 1, end - 1);
    }
    else
        return 0;
}

int main()
{
    int a[5] = {1, 2, 4, 2, 1};
    printf("%d", pal(a, 0, 4));
    int b[5] = {1, 3, 4, 2, 1};
    printf("\n%d", pal(b, 0, 4));
    return 0;
}