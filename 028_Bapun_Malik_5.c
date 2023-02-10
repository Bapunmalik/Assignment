#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int coef;
    int expo;
    struct node *next;
} node;

/* function declaration. */
node *insert(node *ex, int cof, int exp); // function to create a linked list
node *display(node *ex);                  // for display the list
void polysum(node *expr1, node *expr2);   // addition function
void polydiff(node *expr1, node *expr2);  // difference function
void polymulti(node *expr1, node *expr2); // multiplication function

/* Declaring three pointers to store the results of the addition, subtraction and multiplication of the
two polynomials. */
node *sum = NULL;   // pointer to store addition list
node *diff = NULL;  // pointer to store difference list
node *multi = NULL; // pointer to store multiplication list
int main()
{
    node *expr1 = NULL; // pointer to store first expression
    node *expr2 = NULL; // pointer to store second expression

    char ch;
    int cof, exp; // cof:coefficent and exp:exponent of expressions
    int i = 1;
    printf("Enter the first polynomial expression :\n");
    do
    {
        printf("Enter the coefficent of term %d :", i);
        scanf("%d", &cof);
        printf("Enter the exponent of term %d :", i);
        scanf("%d", &exp);
        expr1 = insert(expr1, cof, exp);
        printf("want to add more terms ?(y/n) :");
        scanf("\n");
        scanf("%c", &ch);
        i++;
    } while (ch != 'n');
    i = 1;
    printf("\n");
    printf("Enter the second polynomial expression :\n");
    do
    {
        printf("Enter the coefficent of term %d :", i);
        scanf("%d", &cof);
        printf("Enter the exponent of term %d :", i);
        scanf("%d", &exp);
        expr2 = insert(expr2, cof, exp);
        printf("want to add more terms ?(y/n) :");
        scanf("\n");
        scanf("%c", &ch);
        i++;
    } while (ch != 'n');
    printf("\n\n\n");
    printf("The First Polynomial Expression is:");
    expr1 = display(expr1);
    printf("\n");
    printf("The second Polynomial Expression is:");
    expr2 = display(expr2);
    printf("\n");
    polysum(expr1, expr2);
    printf("The Sum :");
    sum = display(sum);
    polydiff(expr1, expr2);
    printf("\nThe difference :");
    diff = display(diff);
    polymulti(expr1, expr2);
    printf("\nThe multiplication :");
    diff = display(multi);
}

/**
 * It inserts a new node in the linked list in a sorted manner
 *
 * @param ex The head of the linked list
 * @param cof coefficient
 * @param exp The expression to be inserted into.
 *
 * @return the head of the linked list.
 */
node *insert(node *ex, int cof, int exp)
{
    node *t = ex;
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
    while (t != NULL)
    {
        if (t->expo == new_node->expo)
        {
            t->expo = new_node->expo;
            t->coef = t->coef + new_node->coef;
            return ex;
        }
        t = t->next;
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

/**
 * It displays the polynomial
 *
 * @param ex the expression
 *
 * @return The first node of the linked list.
 */
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
/**
 * It adds two polynomials and stores the result in a third polynomial
 *
 * @param expr1 the first polynomial
 * @param expr2 the second polynomial
 *
 * @return Nothing.
 */
void polysum(node *expr1, node *expr2)
{
    while (expr1 != NULL && expr2 != NULL)
    {
        if (expr1->expo < expr2->expo)
        {
            sum = insert(sum, expr2->coef, expr2->expo);
            expr2 = expr2->next;
        }
        else if (expr1->expo > expr2->expo)
        {
            sum = insert(sum, expr1->coef, expr1->expo);
            expr1 = expr1->next;
        }
        else
        {
            sum = insert(sum, expr1->coef + expr2->coef, expr2->expo);
            expr1 = expr1->next;
            expr2 = expr2->next;
        }
    }
    while (expr2 != NULL)
    {
        sum = insert(sum, expr2->coef, expr2->expo);
        expr2 = expr2->next;
    }
    while (expr1 != NULL)
    {
        sum = insert(sum, expr1->coef, expr1->expo);
        expr1 = expr1->next;
    }
    return;
}

/**
 * It takes two polynomials and subtracts them, storing the result in a third polynomial
 *
 * @param expr1 The first polynomial
 * @param expr2 the polynomial to be subtracted from expr1
 *
 * @return Nothing.
 */
void polydiff(node *expr1, node *expr2)
{
    while (expr1 != NULL && expr2 != NULL)
    {
        if (expr1->expo < expr2->expo)
        {
            diff = insert(diff, 0 - expr2->coef, expr2->expo);
            expr2 = expr2->next;
        }
        else if (expr1->expo > expr2->expo)
        {
            diff = insert(diff, expr1->coef, expr1->expo);
            expr1 = expr1->next;
        }
        else
        {
            diff = insert(diff, expr1->coef - expr2->coef, expr2->expo);
            expr1 = expr1->next;
            expr2 = expr2->next;
        }
    }
    while (expr2 != NULL)
    {
        diff = insert(diff, -expr2->coef, expr2->expo);
        expr2 = expr2->next;
    }
    while (expr1 != NULL)
    {
        diff = insert(diff, expr1->coef, expr1->expo);
        expr1 = expr1->next;
    }
    return;
}
// takes address of two expression and multiply them
/**
 * It takes two polynomials and multiplies them together
 *
 * @param expr1 the first polynomial
 * @param expr2  the second polynomial
 *
 * @return Nothing.
 */
void polymulti(node *expr1, node *expr2)
{
    int x, y;
    node *temp = expr2;
    while (expr1 != NULL)
    {

        while (expr2 != NULL)
        {
            x = expr1->coef * expr2->coef;
            if (expr2->expo != 0 && expr1->expo != 0)
            {
                y = expr1->expo + expr2->expo;
            }
            else
            {
                if (expr1->expo == 0)
                    y = expr2->expo;
                else
                    y = expr1->expo;
            }
            multi = insert(multi, x, y);
            expr2 = expr2->next;
        }
        expr1 = expr1->next;
        expr2 = temp;
    }
    return;
}
