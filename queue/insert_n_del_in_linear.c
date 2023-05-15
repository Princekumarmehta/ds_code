#include <stdio.h>
#include <stdio.h>
#define size 5

int rear=-1,front=-1,q[size];
void insertInQ(int item){
    if(rear==size-1){
        printf("stack is empty.\n");;
    }
    else if(rear==-1){
        rear=front=0;
        q[rear]=item;
    }
    else {
        q[++rear]=item;
    }
}
void deleteInQ()
{
    if(rear==-1){
        printf("\nQueue is Empty.");
    }
    else if(rear==0){
        free(q[rear]);
          rear=front=-1;
    }
    else{
        printf("\nDeleted elemetn is : %d",q[front++]);
        
    }
    printf("\n");
}
void printQ(){
    int i;
    if(front>rear){
        printf("Queue is Empty");
    }
    else {
  for(int i=front;i<=rear;i++){
        printf("%d ",q[i]);
  }
    }
  printf("\n");
}
int main()
{
    int opt,item;
    printf("Main-Menu\n1.Insert in queue\t2.Delete element in queue\t3.Dispaly queue\t4.Exit\n");
    scanf("%d",&opt);
    while(opt!=4)
    {
        switch(opt){
            case 1: printf("Enter item to add in queue: ");
               scanf("%d",&item);
               insertInQ(item);
               break;
        case 2: deleteInQ();
        break;
        case 3: printQ();
        break;
        }
        printf("Enter choice: ");
        scanf("%d",&opt);
    }
    return 0;
}