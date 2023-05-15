#include <stdio.h>
#include <stdlib.h>
#define size 5
int s1[size], s2[size], s3[size], top1 = -1, top2 = -1, top3 = -1,  i;


void push(int *top,int *s,int item){
    if(*top>=size-1){
        printf("Stack is full.");
    }
    else {
        *top=*top+1;
        int k=*top;
        *(s+k)=item;
    }
    
}
int pop(int top,int s[]){
    if (top == -1)
    {
        printf("Stack is empty.");
    }
    int ret=s[top];
    top--;
    
    return ret;
    
}
void display(int *top,int *s){
    printf(" '%d' %d\n", top1,*s);
    if(*top==-1){
        printf("Stack is empty.");
    }
    for(i=0;i<=*top;i++){
        printf("%d ",*(s+i));
    }
    printf("\n");
}
int main(){
    int item;
    printf("Enter elements for first Stack: ");
    for(i=0;i<5;i++){
        scanf("%d",item);
        push(&top1,s1,item);
    }
    display(&top1,s1);
    return 0;
}