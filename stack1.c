#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 30 
int a[size] ,top=-1;
int pull(){
    if(top==-1){
        
        return -1;
    }
    else {return a[top--];
    }
}
void push(int element){
    if(top>size-1){
        printf("\nNo Element can be inserted");
    }
    else {top=top+1;
        a[top]=element;
    }
}
void show(){
int i,n=top;
if(top==-1){
    printf("stack is empty.\n");
}
else{
for(i=n;i>=0;i--){
    printf(" \n_____ \n");
    printf("[  %d  ]\n",a[i]);
    printf(" ----- \n");
}
}
}
int main(){
    int choice,res,item;
    printf("Main Menu\n1.Push\t2.Pull\t3.Print\n<--------------------------------------->\n");
    printf("Enter the choice For Stack operation:(-999 to exit)\n");
scanf("%d",&choice);
while(choice!=-999){
    switch(choice){
        case 1: printf("Enter the element you want to push: ");
        scanf("%d ",&item);
        push(item);
        break;
        
        case 2: res=pull();
        if(res==-1)printf("\nStack is empty\n");
        else printf("\nPulled element is %d \n",res);
        break;
       
        case 3: show();
        break;
        default: printf("Enter Correct Choice: \n");
        break;
        
    }
   //printf("Enter choice: \n");
    scanf("%d",&choice);
}
return 0;
}



