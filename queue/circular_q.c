#include <stdio.h>
#include <stdlib.h>
#define size 5
int q[size],rear=-1,front=-1;
void insert(int item){
    if(front==((rear+1)%size))
    {
        printf("queue is full");
    }
    else if(front==-1){
        front=rear=0;
        q[rear]=item;

    }
    else{
        rear=(rear+1)%size;
        q[rear]=item;
    }

}
int peek(){
   if(front==-1){
    printf("Queue is empty");
    return -1;
   }
   else return q[front];
}
void delete()
{
    if(front==-1){
        printf("queue is empty\n");
    }
    else if(front==rear){
        printf("%d is deleted", front);
        rear=front=-1;

    }
    else{
        printf("%d is deleted",front);
        front=(front+1)%size;
    }
}
void display(){
    if(front==-1){
    printf("\nempty");}
    else{
      if(front<=rear){
       for(int i=front;i<=rear;i++){
       printf("%d- ",q[i]);
       }
      }
      else{
        for(int i=front;i<size;i++){
       printf("%d- ", q[i]);
        }
        for (int i =0; i < rear; i++)
        {
       printf("%d- ", q[i]);
        }
      }
    }
}
int main()
{
    int c,item;
    scanf("%d",&c);
    while(c!=5){
    switch(c){
        case 1:printf("Enter item:");
               scanf("%d",&item);
               insert(item);
               break;
        case 2:  printf("%d",peek());
               break;
        case 3:delete();
           break;
        case 4:display();
         break;
        }
        scanf("%d",&c);
    }
    return 0;
    
}