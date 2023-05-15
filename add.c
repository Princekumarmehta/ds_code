/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct node{
    int info;
    struct node *next;
};


void main()
 { struct node *p,*temp,*start=NULL,*new;
   int item,key,add;
   
    printf("Enter Item \n:");
    scanf("%d",&item);
    while(item!=-999){
        p=(struct node *)malloc(sizeof(struct node));
        
        if(start==NULL){
            p->info=item;
            p->next=NULL;
            start=p;
            temp=start;
        }
        else {
            p->info=item;
            p->next=NULL;
            temp->next=p;
            temp=p;
            
        }
        scanf("%d",&item);
    }
    
    
    
    temp=start;
    printf("Enter element after which element has to added and element to be added:\n");
    scanf("%d%d",&key,&add);
    while(temp->info!=key){
        temp=temp->next;
    }
    //printf("%d",temp->info);
    new->info=add;
    new->next=temp->next;
    temp->next=new;
    temp=start;
    while(temp!=NULL){
        printf("%d ",temp->info);
        temp=temp->next;}
}
