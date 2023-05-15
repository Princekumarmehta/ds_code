#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int info;
    struct node *next;
};
struct node *insert_in_beg(struct node *start){
    struct node *p;
    int item;
    printf("Enter element to enter in dll(-999 to eixt): ");
    scanf("%d",&item);
    while(item!=-999){
        p=(struct node *)malloc(sizeof(struct node));
        p->info=item;
        p->prev=NULL;
        if(start==NULL){
            p->next=NULL;
            start=p;
            
        }
        else{
            p->next=start;
            start->prev=p;
            start=p;
        }
        scanf("%d",&item);
    }
    return start;
}
struct node *display(struct node *start){
    struct node *temp=start,*temp2;
    printf("\ndll is: ");
    while(temp!=NULL){
        temp2=temp;
        printf("%d-> ",temp->info);
        temp=temp->next;

    }
    printf("\ndll in reverse order: ");
    while(temp2!=NULL){
        printf("%d-> ",temp2->info);
        temp2=temp2->prev;
    }
return start;

}
struct node *insert_in_end(struct node *start){
    struct node *p,*temp;
    int item;
    printf("Enter element to enter in last od dll: (-999 to exit)");
    scanf("%d",&item);
    while(item!=-999){
        p=(struct node *)malloc(sizeof(struct node));
        p->info=item;
        p->next=NULL;
        if(start==NULL){
            p->next=NULL;
            start=p;
        }
        else{
            temp=start;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=p;
            p->prev=temp;
            
        }
        scanf("%d",&item);

    }
    return start;
}

int main(){
    struct node *start=NULL;
    start=insert_in_beg(start);
    start=display(start);
    printf("\n");
    start=insert_in_end(start);
    start=display(start);
    return 0;
}