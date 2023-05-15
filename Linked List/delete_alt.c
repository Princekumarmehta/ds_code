#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create_Linked(struct node *head)
{
    struct node *temp, *p;
    int item;
    printf("Enter element to enter in linked list(-999 to exit): ");
    scanf("%d", &item);
    while (item != -999)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = item;
        p->next = NULL;
        if (head == NULL)
        {
            head = p;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = p;
            p = temp;
        }
        scanf("%d", &item);
    }
    return head;
}
struct node *dispaly(struct node *head)
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("\nList is Emptty");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
    }
    return head;
}
// 1->2->3->4->5->6->7->8

struct node *delete_alt(struct node *head)
{
    if (head == NULL)
        return head;
    struct node *prev = head;
    struct node *nod = head->next;
    while (prev != NULL && nod != NULL)
    {
        prev->next = nod->next;
        free(nod);
        prev = prev->next;
        if (prev != NULL)
        {
            nod = prev->next;
        }
    }
    return head;
};

int main()
{
    struct node *head = NULL;
    head = create_Linked(head);
    head = dispaly(head);
    head = delete_alt(head);
    printf("\n");
    head = dispaly(head);
    return 0;
}