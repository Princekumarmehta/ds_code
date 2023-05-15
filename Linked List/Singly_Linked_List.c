#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;

struct node *putInLink(int item)
{
    struct node *temp, *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = item;
    p->next = NULL;
    if (start == NULL)
    {
        start = p;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
    return start;
}

struct node *
create()
{
    int item;
    printf("Enter item to insert in Linked List(-999 to eixt): ");
    scanf("%d", &item);
    while (item != -999)
    {
        start = putInLink(item);
        scanf("%d", &item);
    }
    return start;
}
struct node *display()
{
    if (start == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        struct node *temp;
        temp = start;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    return start;
}
struct node *addbeg()
{
    int item;
    printf("Enter Element to enter into ll in begining: ");
    scanf("%d", &item);
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = item;
    p->next = start;
    start = p;
    printf("\n");
    return start;
}
struct node *addend()
{
    int item;
    printf("Enter Element to enter into ll in End ");
    scanf("%d", &item);
    struct node *p, *temp;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = item;
    p->next = NULL;
    temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = p;
    printf("\n");
    return start;
}
struct node *addafternode()
{
    int item, key;
    printf("Enter Element to enter into ll and elementto add after:  ");
    scanf("%d%d", &item, &key);
    struct node *p, *temp;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = item;
    temp = start;

    while (temp->data != key)
    {
        if (temp == NULL)
            break;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("NO KEY ELEMENT FOUND IN LL.");
    }
    else
    {
        p->next = temp->next;
        temp->next = p;
    }

    printf("\n");
    return start;
}
struct node *addbeforenode()
{
    int item, key;
    printf("Enter Element to enter into ll and element to add before:  ");
    scanf("%d%d", &item, &key);
    struct node *p, *temp;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = item;
    temp = start;
    if (start->data == key)
    {
        p->next = start;
        start = p;
    }
    else
    {
        while (temp->next->data != key)
        {
            if (temp == NULL)
                break;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("NO KEY ELEMENT FOUND IN LL.");
        }
        else
        {
            p->next = temp->next;
            temp->next = p;
        }
    }
    printf("\n");
    return start;
}
struct node *deletebeg()
{
    if (start == NULL)
    {
        printf("LIST IS EMPTY");
    }
    else if (start->next == NULL)
    {
        start = NULL;
    }
    else
    {
        struct node *temp = start;

        start = start->next;
        free(temp);
    }
    printf("\n");
    return start;
}
struct node *deletend()
{
    if (start == NULL)
    {
        printf("LIST IS EMPTY");
    }
    else if (start->next == NULL)
    {
        start = NULL;
    }
    else
    {
        struct node *temp, *pretemp;
        temp = start;

        while (temp->next != NULL)
        {
            pretemp = temp;
            temp = temp->next;
        }
        pretemp->next = NULL;
    }
    printf("\n");
    return start;
}
struct node *deletegiven()
{
    int item;
    printf("Enter the item you want to delete: ");
    scanf("%d", &item);
    if (start->data == item)
    {
        start = start->next;
    }
    else
    {
        struct node *temp, *pre;
        temp = start;
        while (temp != NULL && temp->data != item)
        {
            pre = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("item is not in the list");
        }

        else
        {
            temp = temp->next;
            pre->next = temp;
        }
    }
    printf("\n");
    return start;
}
// 3 case basic aprt from null 1.noneed to change start
struct node *deleteafter()
{
    int item;
    printf("Enter the item you want to delete after: ");
    scanf("%d", &item);
    // if (start->data == item)
    // {
    //     start = start->next;
    // }

    struct node *temp, *pre;
    temp = start;
    while (temp != NULL && temp->data != item)
    {

        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("item is not in the list");
    }

    else
    {
        pre = temp;
        temp = temp->next->next;
        pre->next = temp;
    }

    printf("\n");
    return start;
}
struct node *deleteentire()
{
    start = NULL;
    printf("\n");
    return start;
}
// basically we want to store least val in temp1 so traverse temp2 till NULL and find min and store in temp1
struct node *sort()
{
    struct node *temp1, *temp2;
    int temp;
    temp1 = start;
    while (temp1 != NULL)
    {
        temp2 = temp1->next;
        while (temp2 != NULL)
        {
            if (temp1->data > temp2->data)
            {
                temp = temp1->data;
                temp1->data = temp2->data;
                temp2->data = temp;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return start;
}
struct node *count()
{
    struct node *temp;
    int even = 0, odd = 0, total = 0;
    temp = start;
    while (temp != NULL)
    {

        if (temp->data % 2 == 0)
        {
            ++even;
        }
        else
            ++odd;
        ++total;
        temp = temp->next;
    }
    printf("Total number of nodes is %d \nTotal Even nodes is : %d \t Odd is:%d", total, even, odd);
    printf("\n");
    return start;
}
// 4 cases 1.if list is empty else till temp->next!=NULL && temp->data<item
//  2.if we have to insert in beginng(temp==start) 3. in last 4. in btw
struct node *addInSorted()
{
    struct node *temp, *pre;
    int item;
    printf("Enter item to enter in sorted Linked List: ");
    scanf("%d", &item);
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = item;

    if (start == NULL)
    {
        p->next = NULL;
        start = p;
    }
    else
    {
        temp = start;
        while (temp->next != NULL && temp->data < item)
        {
            pre = temp;

            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            p->next = NULL;
            temp->next = p;
        }
        else if (temp == start)
        {
            p->next = start;
            start = p;
        }
        else
        {
            pre->next = p;
            p->next = temp;
        }
    }
    printf("\n");
    return start;
}

int main()
{
    int option;
    printf("Option:\n1.Create  the Linked List \n2.Display the list\n3.Add a node in the begining of the list\n4.Add a node in the end\n5.Add the node before a given node\n6.Add a node after a given node\n7.Delete a node from the beggining\n8.Delete a node from the end \n9.Delete a given node \n10.Delete a node after a given node\n11.Delete the entire list\n12.Sort the list\n13.Add in Sorted\n14.Count number of total,even,odd nodes\n15.Exit\n");
    printf("Enter your option: ");
    scanf("%d", &option);
    while (option != 15)
    {
        switch (option)
        {
        case 1:
            start = create();
            break;
        case 2:
            start = display();
            break;
        case 3:
            start = addbeg();
            break;
        case 4:
            start = addend();
            break;
        case 5:
            start = addbeforenode();
            break;
        case 6:
            start = addafternode();
            break;
        case 7:
            start = deletebeg();
            break;
        case 8:
            start = deletend();
            break;
        case 9:
            start = deletegiven();
            break;
        case 10:
            start = deleteafter();
            break;
        case 11:
            start = deleteentire();
            break;
        case 12:
            start = sort();
            break;
        case 13:
            start = addInSorted();
            break;
        case 14:
            start = count();
            break;
        }
        printf("\nEnter your option: ");
        scanf("%d", &option);
    }

    return 0;
}