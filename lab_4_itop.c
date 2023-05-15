#include <stdio.h>
#include <string.h>
#define size 30
int count=0,pos=0,top=-1,len;
char symb,temp,postfix[size],infix[size],stack[size];
void push(char symb)
{
    top=top+1;
    stack[top]=symb;
}
char pop()
{
    symb=stack[top];
    top=top-1;
    return symb;
}
int preced(char symb)
{
    int p;
    switch(symb)
    {
        case '^': p=3;
        break;
        case '/' :
        case '*' : p=2;
        break;
        case '+' :
        case '-' : p=1;
        break;
        case '(' :
        case ')' : p=0;
        break;
    }
    return p;
}
void itop(char infix[] ,char postfix[])
{
    char symbol,temp;
    len=strlen(infix);
    while(count<len)
    {
        symbol=infix[count];
        switch(symbol)
        {
            case '(':push(symbol);
            break;
            case ')' : temp=pop();
            while(temp!= '('){
                postfix[pos]=temp;
                pos++;
                temp=pop();
            }
            break;
            case '+' :
            case '-':
            case '*':
            case '/':
            case '^': while(preced(stack[top])>=preced(symbol))
            {
                temp=pop();
                postfix[pos]=temp;
                pos++;
            }
            push(symbol);
            break;
            default : postfix[pos++]=symbol;
            break;
        }
        count++;
    }
}
int  main()
{
    char infix[size], postfix[size] ;printf("Enter the infix expression: ");
    scanf("%s",infix);
    itop(infix,postfix);
    printf("\nInfix Expression is: %s",infix);
    printf("\nPostfix Expressiob is : %s",postfix);
    return 0;
}