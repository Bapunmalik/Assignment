#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    char name[30];
    int roll;
    int marks;
    struct node *next;
}node;

node* enQueue(node *rear);
node* deQueue(node *front);
void display(node *front);
int isEmpty(node *front);
void size();

int count=0;

int main()
{   
    node *rear=(node*)malloc(sizeof(node));
    rear->next=NULL;
    node *front=rear;
    int opt;
    while(1){
    printf("--------------------------MENU---------------------------\n");
    printf("\t1.Insert\n\t2.Delete\n\t3.Display\n\t4.Total Student\n\t5.Exit\n");
    printf("Choose an  Option :");
    scanf("%d",&opt);
    switch(opt)
    {
        case 1:
        rear=enQueue(rear);
        break;
        case 2:
        front=deQueue(front);
        break;
        case 3:
        display(front);
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


node* enQueue(node* rear)
{   
    node *new_node=(node*)malloc(sizeof(node));
    fflush(stdin);
    printf("Enter Student Name :");
    gets(new_node->name);
    fflush(stdin);
    printf("Enter RollNumber :");
    scanf("%d",&new_node->roll);
    printf("Enter Marks :");
    scanf("%d",&new_node->marks);
    new_node->next=NULL;
    rear->next=new_node;
    rear=new_node;
    count++;
    return rear;
}


void display(node *front)
{
    front=front->next;
    if(front==NULL)
    {
        printf("No Student Record found\n");
    }
    while(front!=NULL)
    {
        printf("Name  :%s\n",front->name);
        printf("Rollnumber :%d\n",front->roll);
        printf("Marks :%d\n",front->marks);
        front=front->next;
    }
}

node* deQueue(node *front)
{
    node *temp=front;
    if(isEmpty(&(*front))==1)
    {
        printf("Student List is Empty\n");
        return front;
    }
    else
    {
        front=front->next;
        count--;
    }
    free(temp);
    return front;
}

int isEmpty(node *front)
{
    node *temp;
    temp=front->next;
    if(temp==NULL)
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
    printf("Number of Student=%d\n",count);
}