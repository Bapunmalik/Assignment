#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int coef;
    int expo;
    struct node *next;
} node;

node *enqueue(node *ex, int cof, int exp);
node *display(node *ex);
void polysum(node *expr1, node *expr2);
node *sum = NULL;
node *diff = NULL;
node *multi = NULL;
int main()
{
    node *expr1 = NULL;
    node *expr2 = NULL;

    char ch;
    int cof, exp;
    int i = 1;
    printf("Enter the first polynomial expression :\n");
    do
    {
        printf("Enter the coefficent of term %d :", i);
        scanf("%d", &cof);
        printf("Enter the exponent of term %d :", i);
        scanf("%d", &exp);
        expr1 = enqueue(expr1, cof, exp);
        printf("want to add more terms ?(y/n) :");
        scanf("\n");
        scanf("%c", &ch);
        i++;
    } while (ch != 'n');
    i = 1;
    printf("Enter the second polynomial expression :\n");
    do
    {
        printf("Enter the coefficent of term %d :", i);
        scanf("%d", &cof);
        printf("Enter the exponent of term %d :", i);
        scanf("%d", &exp);
        expr2 = enqueue(expr2, cof, exp);
        printf("want to add more terms ?(y/n) :");
        scanf("\n");
        scanf("%c", &ch);
        i++;
    } while (ch != 'n');

    printf("The First Polynomial Expression is:");
    expr1 = display(expr1);
    printf("\n");
    printf("The second Polynomial Expression is:");
    expr2 = display(expr2);
    printf("\n");
    polysum(expr1, expr2);
    printf("The Sum :");
    sum = display(sum);
}

node *enqueue(node *ex, int cof, int exp)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->coef = cof;
    new_node->expo = exp;
    new_node->next = NULL;
    if (ex == NULL)
    {
        ex = new_node;
        return ex;
    }
    if (ex->expo <= new_node->expo)
    {
        ex->next = NULL;
        new_node->next = ex;
        ex = new_node;
        return ex;
    }
    node *temp = ex;
    while (temp->next != NULL && temp->next->expo > new_node->expo)
    {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return ex;
}

node *display(node *ex)
{
    node *temp = ex;
    do
    {
        if (ex->coef > 0)
        {
            printf("+");
        }
        printf("%dx^%d", ex->coef, ex->expo);
        ex = ex->next;
    } while (ex != NULL);
    return temp;
}

void polysum(node *expr1, node *expr2)
{   
    node *temp;
    node *new_node = (node *)malloc(sizeof(node));
    while (expr1 != NULL || expr2 != NULL)
    {
        if (expr1->expo < expr2->expo)
        {
            new_node->coef = expr2->coef;
            new_node->expo = expr2->expo;
            new_node->next = NULL;
            if (sum == NULL)
            {
                sum = new_node;
                temp = sum;
            }
            expr2 = expr2->next;
        }
        else if (expr1->expo > expr2->expo || expr2 == NULL)
        {
            new_node->coef = expr1->coef;
            new_node->expo = expr1->expo;
            new_node->next = NULL;
            if (sum == NULL)
            {
                sum = new_node;
                temp = sum;
            }
            expr1 = expr1->next;
        }
        else
        {
            new_node->coef = expr1->coef + expr2->coef;
            new_node->expo = expr1->expo;
            new_node->next = NULL;
            temp->next = new_node;
            if (sum == NULL)
            {
                sum = new_node;
                temp = sum;
            }
            expr1 = expr1->next;
            expr2 = expr2->next;
        }
        
        if(temp!=sum)
        {
        temp->next = new_node;
        temp = new_node;
        }
    }
    return;
}