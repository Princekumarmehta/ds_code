#include <stdio.h>
#include <stdlib.h>
int count = 0;
int toh(int n,char s ,char t, char d)
{ 
    if(n>0)
    {
        
        toh(n - 1, s, d, t);
        {
            printf("\n %d. Move  disc %d from %c to %c ",++count, n, s, d);
        }
        toh(n - 1, t, s, d);
        
    }
    return count;
}
int main()
{
    int n,count;
    
    printf("Enter no of disc in Toh: ");
    scanf("%d",&n);
    count=toh(n,'a','b','c');
    printf("\nTotal no of moves is : %d",count);
    return 0;
}