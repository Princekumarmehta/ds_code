#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};
struct node *insert_at_end(int item, struct node *start)
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
        struct node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
    return start;
}
struct node *insert_at_beg(int item, struct node *start)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = item;
    if (start == NULL)
    {
        p->next = NULL;
        start = p;
    }
    else
    {
        p->next = start;
        start = p;
    }
    return start;
}
int count(struct node *start)
{
    struct node *temp = start;
    int c = 0;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}
struct node *delete_nth(struct node *start)
{
    int n;
    printf("\nenter the value of nth to delete: ");
    scanf("%d", &n);
    if (n > count(start) || n < 1)
    {
        printf("\nDeletetion is not possible.");
    }
    else
    {
        struct node *temp = start, *temp2;
        if (n == 1)
        {
            printf("\nDeleted element is %d ", start->info);
            start = start->next;
            free(temp);
        }
        else if (n == count(start))
        {
            while (temp->next != NULL)
            {
                temp2 = temp;
                temp = temp->next;
            }
            printf("\nDeleted element is %d", temp->info);
            temp2->next = NULL;
            free(temp);
        }
        else
        {
            while (n--)
            {
                temp2 = temp;
                temp = temp->next;
            }
            printf("\ndeleted element is %d", temp->info);
            temp2->next = temp->next;
            free(temp);
        }
    }
    return start;
}
struct node *display(struct node *start)
{
    if (start == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        struct node *temp = start;

        while (temp != NULL)
        {
            printf(" %d->", temp->info);
            temp = temp->next;
        }
    }
    return start;
}
struct node *sort(struct node *start)
{
    if (start == NULL)
    {
        printf("\nlist is empty.");
    }
    else
    {
        struct node *temp1, *temp2;
        int min;
        temp1 = start;
        while (temp1 != NULL)
        {
            temp2 = temp1;
            min = temp1->info;
            while (temp2 != NULL)
            {
                if (temp2->info < min)
                {
                    min = temp2->info;
                    temp2->info = temp1->info;
                    temp1->info = min;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
    }
    return start;
}
int main()
{
    struct node *start = NULL;
    int opt = 0, item;
    printf("Main-Menu\n1.Insert at end \n2.Insert_at_beg\n3.sort\n4.Display\n5.Exit\n6.Deleted nth element: ");
    while (opt != 5)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("\nEnter a number to insert at last: ");
            scanf("%d", &item);
            start = insert_at_end(item, start);
            break;
        case 2:
            printf("\nEnter a number to insert at beg: ");
            scanf("%d", &item);
            start = insert_at_beg(item, start);
            break;
        case 3:
            start = sort(start);
            break;
        case 4:
            start = display(start);
            break;
        case 6:
            start = delete_nth(start);
            break;
        }
    }
    return 0;
}