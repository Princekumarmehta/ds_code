#include <stdio.h>
#include <stdlib.h>

struct node
{
    float coeff;
    int px;
    int py;

    struct node *next;
};

struct node *add_poly(struct node *poly1, struct node *poly2)
{
}

struct node *insert_in_poly(struct node *poly, float cf, int cx, int cy)
{

    struct node *temp, *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->coeff = cf;
    p->px = cx;
    p->py = cy;
    p->next = NULL;
    if (poly == NULL)
    {
        poly = p;
        p = poly;
    }
    else
    {
        temp = poly;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
    return poly;
}

struct node *create_poly(struct node *poly)
{
    float cf;
    int x, y;
    while (1)
    {
        printf("Enter the terms:\n");
        printf("Enter the coeffiecient value(-999 to exit): ");
        scanf("%f", &cf);
        if (cf == -999)
            break;
        printf("\nEnter the degree of x and y: ");
        scanf("%d%d", &x, &y);
        poly = insert_in_poly(poly, cf, x, y);
    }
    return poly;
}
struct node *display(struct node *poly)
{
    struct node *temp = poly;
    while (temp != NULL)
    {
        printf("%.2f(x)%d(y)% + ", temp->coeff, temp->px, temp->py);
        temp = temp->next;
    }
    printf("\n");
    return poly;
}

int main()
{

    struct node *poly1 = NULL, *poly2 = NULL;
    poly1 = create_poly(poly1);
    printf("Poly 1 is: \n");
    poly1 = display(poly1);
    poly2 = create_poly(poly2);
    printf("Poly 2 is: \n");
    poly2 = display(poly2);

    return 0;
}