// ALL OPERATION OF HLL
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create_hll(struct node *start)
{
    int item;
    struct node *p, *temp;
    printf("Enter the value of data to be entered in hll(-999 to exit): ");
    scanf("%d", &item);
    while (item != -999)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = item;
        p->next = NULL;
        if (start == NULL)
        {
            start = (struct node *)malloc(sizeof(struct node));
            start->next = p;
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
        scanf("%d", &item);
    }
    return start;
}
struct node *display(struct node *start)
{
    struct node *temp;
    temp = start;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    return start;
}
struct node *insert_front(struct node *start)
{
    struct node *p;
    int item;
    printf("\nEnter element to add front: ");
    scanf("%d", &item);
    p = (struct node *)malloc(sizeof(struct node));
    p->data = item;
    p->next = NULL;

    if (start == NULL)
    {
        start = (struct node *)malloc(sizeof(struct node));

        start->next = p;
    }
    else
    {
        struct node *temp;
        temp = start->next;
        start->next = p;
        p->next = temp;
    }
    return start;
}
struct node *insert_rear(struct node *start)
{
    struct node *p, *temp;
    int item;
    printf("\nEnter item to insert rear in hll: ");
    scanf("%d", &item);
    p = (struct node *)malloc(sizeof(struct node));
    p->data = item;
    p->next = NULL;
    if (start == NULL)
    {
        start = (struct node *)malloc(sizeof(struct node));

        start->next = p;
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
struct node *delete_rear(struct node *start)
{
    if (start == NULL || start->next == NULL)
    {
        return NULL;
    }
    else
    {
        struct node *curr, *prev;
        curr = start->next;

        while (curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        free(curr);
    }
    return start;
}
struct node *delete_front(struct node *start)
{
    if (start == NULL || start->next == NULL)
    {
        return NULL;
    }
    else
    {
        struct node *temp = start->next;
        start->next = temp->next;
        free(temp);
    }
    return start;
}

int main()
{
    int option;
    printf("Enter the option:\n1.create Linked l\n2.insert front\n3.insert rear\n4.delete front\n5.delete rear\n6.show\n7.exit\n");
    scanf("%d", &option);
    while (option != 7)
    {
        switch (option)
        {
        case 1:
            start = create_hll(start);
            break;
        case 2:
            start = insert_front(start);
            break;
        case 3:
            start = insert_rear(start);
            break;
        case 4:
            start = delete_front(start);
            break;
        case 5:
            start = delete_rear(start);
            break;
        case 6:
            start = display(start);
            break;

        default:
            printf("\nEnter correct value fro option:\n");
            break;
        }
        printf("\nEnter your choice : ");
        scanf("%d", &option);
    }
    return 0;
}