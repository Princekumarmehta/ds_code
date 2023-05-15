#include <stdio.h>
#include <math.h>
#include <string.h>
#define size 30
int a[size],top=-1;
void push(int item){
    if(top==size-1){
        printf("\nInsertion is not possible.");
    }
    else{
        
    top=top+1;
    a[top]=item;
    }
}
int pop(){
    if(top==-1){
        printf("\nstack is empty.\n");
        return -999;
    }
    else{
        return a[top--];
    }
}
int is_dig(char symbol)
{
    return (symbol>='0' && symbol<='9');
}
int op(int op1, int op2, int symbol){
    switch(symbol)
    {
        case '+' :return (op1+op2);
        case '-' : return (op1-op2);
        case '*' : return (op1*op2);
        case '^' :return (pow(op1,op2));
        case '/' : return(op1/op2);
    }
}
int main()
{
char symbol,postfix[30];
int op1,op2,res,i;
printf("Enter the postfix expression: ");
scanf("%s",postfix);
for(i=0;i<strlen(postfix);i++){
    symbol=postfix[i];
    if(is_dig(symbol)){
        push(symbol-'0');
    }
    else{
        op1=pop();
        op2=pop();
        res=op(op1,op2,symbol);
        push(res);
    }
}
printf("\nValue of postfix is : %d",pop());
return 0;
}