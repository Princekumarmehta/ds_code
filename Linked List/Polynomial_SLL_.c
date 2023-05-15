#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    float coeff;
    int px;
    int py;
    struct node *next;
};
struct node *poly = NULL;
float evaluate_poly(struct node *poly)
{
    float ans = 0.0;
    int x, y;
    printf("\nEnter value of x and y to evaluate polynomial: ");
    scanf("%d%d", &x, &y);
    struct node *temp;
    temp = poly;
    while (temp != NULL)
    {
        ans = ans + temp->coeff * (pow(x, temp->px)) * (pow(y, temp->py));
        temp = temp->next;
    }

    return ans;
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

struct node *create_poly()
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

int main()
{

    poly = create_poly(poly);
    float ans = evaluate_poly(poly);
    printf("%f", ans);
    return 0;
}