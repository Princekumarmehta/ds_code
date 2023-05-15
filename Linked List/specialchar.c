#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
char FindSpecialChar(char *string)
{
    struct node *p = (struct node *)
        malloc(sizeof(struct node));
    struct node *q = p;
    int n = strlen(string);
    int i;
    for (i = 0; i < n - 1; i++)
    {
        p->data = string[i];
        p->next = (struct node *)
            malloc(sizeof(struct node));
        p = p->next;
        p->next = NULL;
    }
    p->data = string[n - 1];
    p = q;
    while (p != NULL)
    {
        printf("%c", p->data);
        p = p->next;
    }
    p = q;
    while (p)
    {
        p = p->next;
        if (p)
        {
            p = p->next;
            q = q->next;
        }
    }
    return q->data;
}
// B->M->S->C->E
int main()
{
    char a[5] = "BMSCE";
    char b[11] = "Information";
    char c[14] = "DataStructure";
    // printf("\n%c", FindSpecialChar(a));
    printf("\n%c", FindSpecialChar(b));
    // printf("\n%c", FindSpecialChar(c));
    return 0;
}