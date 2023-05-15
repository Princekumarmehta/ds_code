#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};
struct node *create_ll(struct node *start)
{
    struct node *p, *temp;
    int item;

    printf("Enter item to add in sorted linked list(-999 to terminate): \n");
    scanf("%d", &item);
    while (item != -999)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->info = item;
        p->next = NULL;
        if (start == NULL)
        {
            start = p;
            temp = start;
        }
        else
        {
            temp->next = p;
            temp = p;
        }
        scanf("%d", &item);
    }
    return start;
}
struct node *display(struct node *start)
{
    struct node *temp = start;
    while (temp != NULL)
    {
        printf("%d-> ", temp->info);
        temp = temp->next;
    }
    return start;
}
struct node *insert_in_sorted(struct node *start)
{
    struct node *p, *temp, *temp2;
    int item;
    temp = start;
    printf("Enter element to add in sorted linked list: ");
    scanf("%d", &item);
    p = (struct node *)malloc(sizeof(struct node));
    p->info = item;
    if (start == NULL)
    {
        p->next = NULL;
        start = p;
    }
    else if (start->info > item)
    {
        p->next = start;
        start = p;
    }

    else
    {

        while (temp->info < item && temp->next != NULL)
        {
            temp2 = temp;
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            p->next = NULL;
            temp->next = p;
        }
        else
        {

            temp2->next = p;
            p->next = temp;
        }
    }
    return start;
}

int main()
{
    struct node *start = NULL;
    start = create_ll(start);
    printf("\n");
    start = display(start);
    printf("\n");
    start = insert_in_sorted(start);
    printf("\n");
    printf("After insertion:\n");
    start = display(start);
    return 0;
}
