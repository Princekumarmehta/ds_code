#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *insert_last(int item, struct node *start)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = item;
    p->next = NULL;
    if (start == NULL)
    {
        start = p;
    }
    else
    {
        struct node *temp;
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
    return start;
}
struct node *delete_beg(struct node *start)
{
    struct node *temp = start;
    if (start == NULL)
    {
        printf("\nList is empty");
    }

    else
    {
        start = start->next;
        printf("\nDeleted element is %d ", temp->info);
        free(temp);
    }
    return start;
}
struct node *display(struct node *start)
{
    struct node *temp = start;
    if (start == NULL)
    {
        printf("List is Empty");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d-> ", temp->info);
            temp = temp->next;
        }
    }
    printf("\n");
    return start;
}
int main()
{
    int opt = 0, item;
    struct node *start = NULL;
    printf("Main-Menu\n1.Insert at end \n2.Delete_beg\n3.Display\n4.Exit");
    while (opt != 4)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("\nEnter a number to insert at last: ");
            scanf("%d", &item);
            start = insert_last(item, start);
            break;
        case 2:
            start = delete_beg(start);
            break;
        case 3:
            start = display(start);
            break;
        }
    }
    return 0;
}