#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    char name[30];
    int roll;
    int marks;
    struct node *next;
}node;

int count=0;
node* push(node *head);
node* pop(node *head);
int isEmpty(node *head);
void size();
void display(node *head);


int main()
{   
    int opt;
    node *head=(node*)malloc(sizeof(node));
    head->next=NULL;
    node *temp=head;
    while(1){
    printf("--------------------------MENU---------------------------\n");
    printf("\t1.Insert\n\t2.Delete\n\t3.Display\n\t4.Total Student\n\t5.Exit\n");
    printf("Choose an  Option :");
    scanf("%d",&opt);
    switch(opt)
    {
        case 1:
        head=push(head);
        break;
        case 2:
        head=pop(head);
        break;
        case 3:
        display(head);
        break;
        case 4:
        size();
        break;
        case 5:
        exit(0);
        break;
        default:
        printf("Wrong input\n");
    }
    }
}


node* push(node *head)
{   
    node *new_node=(node*)malloc(sizeof(node));
    fflush(stdin);
    printf("Enter Student  Name :");
    gets(new_node->name);
    fflush(stdin);
    printf("Enter RollNumber :");
    scanf("%d",&new_node->roll);
    printf("Enter Marks :");
    scanf("%d",&new_node->marks);
    new_node->next=head;
    head=new_node;
    count++;
    return head;
}


node* pop(node *head)
{   
    node* temp;
    if(isEmpty(&(*head))==1)
    {
        printf("Student List is Empty\n");
    }
    else
    {
     temp=head;
     head=head->next;
    printf("Record deleted Successfully\n");
    free(temp);
    count--;
    }
    return head;
}


void display(node *head)
{   
    if(head->next==NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
    while(head->next!=NULL)
    {
        printf("Student Name :%s\n",head->name);
        printf("Student RollNumber :%d\n",head->roll);
        printf("Student Marks :%d\n",head->marks);
        head=head->next;
    }
    }
}


int isEmpty(node *head)
{
    if(head->next==NULL)
    {
    return 1;
    }
    else
    {
        return 0;
    }
}


void size()
{
    printf("Number of student =%d\n",count);
}