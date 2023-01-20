#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;

node* head = NULL;

void insert(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL || head->data >= newNode->data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    node* temp = head;
    while(temp->next != NULL && temp->next->data < newNode->data) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void printList() {
    node* temp = head;
    while(temp != NULL) {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n,val;
    printf("Enter How Many data to insert ?");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter Value %d :",i+1);
        scanf("%d",&val);
        insert(val);
    }
    printList();

    return 0;
}
