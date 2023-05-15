#include <stdio.h>
#include <stdlib.h>
#define size 5
int top1 = -1, top2 = -1, top3 = -1;
int s1[size], s2[size], s3[size];
void push1(int n)
{
    if (top1 == size - 1)
        printf("stack overload\n");
    else
        top1++;
    s1[top1] = n;
}
void push2(int n)
{
    if (top2 == size - 1)
        printf("stack overload\n");
    else
        top2++;
    s2[top2] = n;
}
void push3(int n)
{
    if (top3 == size - 1)
        printf("stack overload\n");
    else
        top3++;
    s3[top3] = n;
}

int pop1()
{
    int n;
    if (top1 == -1)
        printf("stack underflow\n");
    else
        n = s1[top1];
    top1--;
    return n;
}
int pop2()
{
    int n;
    if (top2 == -1)
        printf("stack underflow\n");
    else
        n = s2[top2 ];
    top2--;
    return n;
}
int pop3()
{
    int n;
    if (top3 == -1)
        printf("stack underflow\n");
    else
        n = s3[top3];
    top3--;
    return n;
}
void display()
{
    if (top1 == -1)
        printf("stack underflow\n");
    else
        for (int i = top1; i >= 0; i--)
        {
            printf("%d\n", s1[i]);
        }
}
void display2()
{
    if (top2 == -1)
        printf("stack underflow\n");
    else
        for (int i = top2; i >= 0; i--)
        {
            printf("%d\n", s2[i]);
        }
}
void display3()
{
    if (top3 == -1)
        printf("stack underflow\n");
    else
        for (int i = top3; i >= 0; i--)
        {
            printf("%d\n", s3[i]);
        }
}
int main()
{
    int i, n;
    push1(1);
    push1(2);
    push1(3);
    push1(4);
    push1(5);
display();
printf("\n-----");
printf("\n");
    for (int i = 4; i >= 0; i--)
    {
        n = pop1();
        push2(n);
    }
    printf("%d\n",top2);
    display2();
    printf("\n-----");
    for (int i = 4; i >= 0; i--)
    {
        n = pop2();
        push3(n);
    }
    printf("%d\n", top3);
    display3();
    printf("\n-----");
    printf("\ntop1:%d\ntop3:%d\n",top1,top3);
    for (int i =4; i >= 0; i--)
    {
        n = pop3();
        push1(n);
    }
    printf("\ntop1:%d\ntop3:%d\n", top1, top3);
    display();
}