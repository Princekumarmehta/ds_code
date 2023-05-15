#include <stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int info;
    struct node *next;
};
struct node *create_dll(struct node *start)
{
    struct node *temp,*p;
    int item;
    printf("Enter the element you want to insert in dll(-999 to exit): \n");
    scanf("%d",&item);
    while(item!=-999){
        p=(struct node *)malloc(sizeof(struct node));
        p->info=item;
        p->next=NULL;
        if(start==NULL){
            p->prev=NULL;
            start=p;
            temp=start;
        }
        else{
            temp->next=p;
            p->prev=temp;
            temp=p;
        }
        scanf("%d",&item);
    }
    return start;

}

struct node *display(struct node *start){
    struct node *temp=start;
    while(temp!=NULL){
        printf("%d->",temp->info);
        temp=temp->next;
    }
    return start;
}
int count(struct node  *start){
    int con=0;
    struct node *temp=start;
    while(temp!=NULL){
        con++;
        temp=temp->next;
    }
    return con;
}
struct node *delete_mid(struct node *start){
    struct node *temp,*temp2;
    temp=start;
    int coun=count(start);
    coun=coun/2;
    while(coun--){
        temp2=temp;
        temp=temp->next;
    }
    temp2->next=temp->next;
    temp->next->prev=temp2;
    free(temp);
    return start;
}
struct node *insert_before_key(struct node *start)
{ struct node *p,*temp,*temp2;
   int key,item;
   if(start==NULL){
    printf("\nInsertion is not possible.");
   }
   else{
       p=(struct node*)malloc(sizeof(struct node));
       printf("\nEnter key for insertion: ");
       scanf("%d",&key);
       printf("\nenter element to add in dll: ");
       scanf("%d",&item);
       if(start->info==key){
            p->info = item;
            p->prev=NULL;
            p->next=start;
            start->prev=p;
            start=p;
       }
       else{
      temp=start;
      while(temp->info!=key && temp!=NULL ){
        temp2=temp;
        temp=temp->next;
      }
      if(temp2->next==NULL){
        printf("\nelement not there.");
        return start;
      }
      else{
        p->info=item;
        temp2->next=p;
        p->prev=temp2;
        p->next=temp;
        temp->prev=p;
      }
       }
   }
return start;
}
int main(){
struct node *start=NULL;
start=create_dll(start);
start=display(start);

start=insert_before_key(start);
printf("\nAfter insertion: ");
start=display(start);
printf("\ndeleting mid: ");
start=delete_mid(start);
start=display(start);
return 0;
}